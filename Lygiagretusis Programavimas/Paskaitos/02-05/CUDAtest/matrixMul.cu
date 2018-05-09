/*
* Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
*
* NVIDIA Corporation and its licensors retain all intellectual property and
* proprietary rights in and to this software and related documentation and
* any modifications thereto.  Any use, reproduction, disclosure, or distribution
* of this software and related documentation without an express license
* agreement from NVIDIA Corporation is strictly prohibited.
*
*/

/* Matrix multiplication: C = A * B.
* Host code.
*
* This sample implements matrix multiplication and is exactly the same as
* Chapter 7 of the programming guide.
* It has been written for clarity of exposition to illustrate various CUDA
* programming principles, not with the goal of providing the most
* performant generic kernel for matrix multiplication.
*
* CUBLAS provides high-performance matrix multiplication.
*/

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <omp.h>

// includes, project
#include "matrixMul.h"
// includes, kernels
#include "matrixMul_kernel.cuh"
#include "matrixMul_naive.cuh"
#include "matrixMul_tiling.cuh"
#include "matrixMul_coalescing.cuh"
#include "matrixMul_noBankConflict.cuh"
#include "matrixMul_compOpt.cuh"
#include "matrixMul_unroll.cuh"
#include "matrixMul_prefetch.cuh"

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest(int testNum);
void randomInit(float*, int);
void printDiff(float*, float*, int, int);

//extern "C"
//void computeGold(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

void computeGold(float* C, const float* A, const float* B, unsigned int hA, unsigned int wA, unsigned int wB)
{
	for (unsigned int i = 0; i < hA; ++i)
		for (unsigned int j = 0; j < wB; ++j) {
			double sum = 0;
			for (unsigned int k = 0; k < wA; ++k) {
				double a = A[i * wA + k];
				double b = B[k * wB + j];
				sum += a * b;
			}
			C[i * wB + j] = (float)sum;
		}
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	// By default, we use device 0, otherwise we override the device ID based on what is provided at the command line
	int devID = 0;
	//cudaSetDevice(devID);
	cudaError_t error;
	cudaDeviceProp deviceProp;
	error = cudaGetDevice(&devID);

	if (error != cudaSuccess)
	{
		printf("cudaGetDevice returned error code %d, line(%d)\n", error, __LINE__);
	}

	error = cudaGetDeviceProperties(&deviceProp, devID);

	if (deviceProp.computeMode == cudaComputeModeProhibited)
	{
		fprintf(stderr, "Error: device is running in <Compute Mode Prohibited>, no threads can use ::cudaSetDevice().\n");
		exit(EXIT_SUCCESS);
	}

	if (error != cudaSuccess)
	{
		printf("cudaGetDeviceProperties returned error code %d, line(%d)\n", error, __LINE__);
	}
	else
	{
		printf("GPU Device %d: \"%s\" with compute capability %d.%d\n", devID, deviceProp.name, deviceProp.major, deviceProp.minor);
	}

	for(int i = 0;i<=7;i++)
		runTest(i);

	exit(EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void runTest(int testNum)
{

	/****************************************************/
	/*  Preparations                                    */
	/****************************************************/

	printf("[CUDA Matrix Multiply Using Version %d ] - Starting ...\n", testNum);

	// utilities
	cudaEvent_t start;
	cudaEvent_t stop;
	float msecTotal;


	// allocate host memory for matrices A and B
	unsigned int size_A = WA * HA;
	unsigned int mem_size_A = sizeof(float) * size_A;
	float* h_A = (float*)malloc(mem_size_A);//galima naudoti ir new float[size_A]
	unsigned int size_B = WB * HB;
	unsigned int mem_size_B = sizeof(float) * size_B;
	float* h_B = (float*)malloc(mem_size_B);
	float flop = 2 * (float)WC * (float)HC * (float)WA;

	// set seed for rand()
	srand(2017);
	// initialize host memory
	randomInit(h_A, size_A);
	randomInit(h_B, size_B);

	// allocate device memory
	float* d_A;
	cudaMalloc((void**)&d_A, mem_size_A);
	float* d_B;
	cudaMalloc((void**)&d_B, mem_size_B);

	// allocate device memory for result
	unsigned int size_C = WC * HC;
	unsigned int mem_size_C = sizeof(float) * size_C;
	float* d_C;
	cudaMalloc((void**)&d_C, mem_size_C);

	// allocate host memory for the result
	float* h_C = (float*)malloc(mem_size_C);

#if CHECK_RESULT == 1
	// create and start timer
	/*cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, NULL);*/
	double t1 = omp_get_wtime();
	// compute reference solution
	float* reference = (float*)malloc(mem_size_C);
	computeGold(reference, h_A, h_B, HA, WA, WB);
	// stop and destroy timer
	double t2 = omp_get_wtime();
	/*cudaEventRecord(stop, NULL);
	cudaEventSynchronize(start);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&msecTotal, start, stop);*/
	msecTotal =1000.* (t2 - t1) ;
	//printf("Naive CPU (Golden Reference)\n");
	printf("CPU processing time: %f (ms), GFLOPS: %f \n", msecTotal, ((flop/1.e+9) / (msecTotal / 1.e+3)));
	//printf("Processing time2: %f (ms), \n", t2-t1);
#endif

	dim3 threads, grid;

	/****************************************************/
	/*  CUDA SDK example                                */
	/****************************************************/

	// create and start timer
	// copy host memory to device
	// setup execution parameters
	/*cudaEventCreate(&start);
	cudaEventRecord(start, NULL);*/
	t1 = omp_get_wtime();
	cudaMemcpy(d_A, h_A, mem_size_A, cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, mem_size_B, cudaMemcpyHostToDevice);
	threads = dim3(BLOCK_SIZE, BLOCK_SIZE);
	grid = dim3(WC / threads.x, HC / threads.y);

	// execute the kernel
	switch (testNum) {
	case 0:
		matrixMul <<< grid, threads >>> (d_C, d_A, d_B, WA, WB);
		break;
	case 1:
		matrixMul_naive <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 2:
		matrixMul_tiling <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 3:
		matrixMul_coalescing <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 4:
		matrixMul_noBankConflict <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 5:
		threads = dim3(BLOCK_SIZE, 4);
		grid = dim3(WC / (BLOCK_SIZE * 4), HC / BLOCK_SIZE);
		matrixMul_compOpt <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 6:
		threads = dim3(BLOCK_SIZE, 4);
		grid = dim3(WC / (BLOCK_SIZE * 4), HC / BLOCK_SIZE);
		matrixMul_unroll <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	case 7:
		threads = dim3(BLOCK_SIZE, 4);
		grid = dim3(WC / (BLOCK_SIZE * 4), HC / BLOCK_SIZE);
		matrixMul_prefetch <<< grid, threads >>>(d_C, d_A, d_B, WA, WB);
		break;
	}
	// copy result from device to host
	cudaMemcpy(h_C, d_C, mem_size_C, cudaMemcpyDeviceToHost);
	/*cudaEventCreate(&stop);
	cudaEventRecord(stop, NULL);
	cudaEventSynchronize(start);
	cudaEventSynchronize(stop);*/
	// stop and destroy timer
	//cudaEventElapsedTime(&msecTotal, start, stop);
	t2 = omp_get_wtime();
	msecTotal =1000.*(t2-t1);
	//printf("GPU SDK Sample\n");
	printf("Processing time: %f (ms), GFLOPS: %f \n\n", msecTotal, flop / msecTotal / 1e+6);
#if CHECK_RESULT == 1
	// check result
	printDiff(reference, h_C, WC, HC);
#endif

	/****************************************************/
	/*  Cleaning                                        */
	/****************************************************/

	// clean up memory
	free(h_A);
	free(h_B);
	free(h_C);
#if CHECK_RESULT == 1
	free(reference);
#endif
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	//cudaThreadExit();
}

// Allocates a matrix with random float entries.
void randomInit(float* data, int size)
{
	for (int i = 0; i < size; ++i)
		data[i] = ((float)rand()) / (float)RAND_MAX;
}

void printDiff(float *data1, float *data2, int width, int height)
{
	int i, j, k;
	int error_count = 0;
	for (j = 0; j<height; j++) {
		for (i = 0; i<width; i++) {
			k = j*width + i;
			if (fabs(data1[k] - data2[k]) > 0.1) {
				printf("diff(%d,%d) CPU=%4.4f, GPU=%4.4f \n", i, j, data1[k], data2[k]);
				error_count++;
				if(error_count>2)
					return;
			}
		}
	}
	printf("Total Errors = %d \n", error_count);
}

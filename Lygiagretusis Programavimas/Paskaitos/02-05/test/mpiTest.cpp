// GraphAlg.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <omp.h>
//#include <mpi.h>

using namespace std;

void memBegin(double** &M, int** &P, const int n);
void memGen(double** &M, int** &P, const int n);
void memPrint(double** &M, int** &P, const int n, bool printP = false);
void memInit(double** &M, int** &P, const int n);
void memEnd(double** &M, int** &P, const int n);

void printPath(int i, int j, int **P);

void serial(int N) {
	double t1, t2, t3, t4;
	t1 = omp_get_wtime();
	double **D;
	int **P;
	memBegin(D, P, N);
	srand(1); memGen(D, P, N);
	memInit(D, P, N);
	//memPrint(D, P, N);
#pragma omp barrier
	t2 = omp_get_wtime();
	for (int k = 0; k < N; k++) {
		//sekancio ciklo veiksmai yra tarpusavyje nepriklausomi
		//k-taja eilute reikia issiusti visiems
#pragma omp parallel for
		for (int i = 0; i < N; i++) {
			if (i != k)
				for (int j = 0; j < N; j++)
					if (j != k && i != j && D[i][k] > 0 && D[k][j] > 0) {
						double d = D[i][k] + D[k][j];
						if (D[i][j] < 0 || d < D[i][j]) {
							D[i][j] = d;
							P[i][j] = k;
						}
					}
		}
		//pries vykdant sekancia iteracija reikia sinchronizuoti duomenis
	}




	//visiems reikia nusiusti savo duomenis nuliniam processui
	t3 = omp_get_wtime();
	int v1 = 0;
	int v2 = N / 2;
	//cout << "Trumpiausias atstumas nuo " << v1 << " iki " << v2 << " yra lygus " << D[v1][v2] << endl;
	//cout << "Trumpiausias Kelias: ";
	//cout << v1 << " -> "; printPath(v1, v2, P); cout << v2 << endl;
	memEnd(D, P, N);
	t4 = omp_get_wtime();
	//cout << "laikai:" << endl << t2 - t1 << endl << t3 - t2 << endl << t4 - t3 << endl;
	cout << N << "  " << t3 - t2 << endl;
	//cout << "visas:" << t4 - t1 << " ;  skaiciavimai: " << endl << t3 - t2 << endl;
	///cout << "skaiciavimu dalis: " << (t3 - t2) / (t4 - t1) << endl;
}
/*
void parallelMPItest(int argc, char *argv[]) {
	int size, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double t1, t2, t3, t4;
	t1 = MPI_Wtime();
	double **D;
	int **P;
	int N;
	N = 1000;
	memBegin(D, P, N);
	//double *buf = new double[N];
	srand(1); memGen(D, P, N);
	memInit(D, P, N);
	t2 = MPI_Wtime();
	if (!rank)
		;// memPrint(D, P, N);
	for (int i = 0; i < N; i++) {
		int owner = i % size;
		if(rank == owner)
			for (int j = 0; j < N; j++) {
				D[i][j] += j*i;
			}
	}
	int k = 20;
	int owner = k % size;
	MPI_Bcast(D[k], N, MPI_DOUBLE, owner, MPI_COMM_WORLD);
	for (int i = 0; i < N; i++) {
		int owner = i % size;
		if (rank == owner)
			for (int j = 0; j < N; j++) {
				D[i][j] += D[k][j];
			}
	}

	int kiek = 0;
	double *kth;
	for (int i = 0; i < N; i++) {
		int sender = i % size;
		if (rank != 0) {
			if (sender == rank) {
				MPI_Send(D[i], N, MPI_DOUBLE, 0, 3, MPI_COMM_WORLD);
				//MPI_Send(P[i], N, MPI_INT, 0, 4, MPI_COMM_WORLD);
			}
		}
		else {
			if (sender != rank) {
				MPI_Status stat;
				MPI_Recv(D[i], N, MPI_DOUBLE, sender, 3, MPI_COMM_WORLD, &stat);
				//MPI_Recv(P[i], N, MPI_INT, sender, 4, MPI_COMM_WORLD, &stat);
			}
		}
	}
	t3 = MPI_Wtime();
	//delete[] buf;
	memEnd(D, P, N);
	MPI_Finalize();
}
*/
int main(int argc, char *argv[])
{
	for(int N=10;N<2000;N*=2)
	serial(N);
	//parallelMPItest(argc, argv);
	return 0;
}

void printPath(int i, int j, int **P) {
	int k = P[i][j];
	if (k != 0) {
		printPath(i, k, P);
		cout << k << " -> ";
		printPath(k, j, P);
	}
}

void memBegin(double** &M, int** &P, const int n) {
	M = new double*[n];
	P = new int*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
		P[i] = new int[n];
	}
}

void memGen(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rand() % 2)
				M[i][j] = 1 + rand() % 100;
			else
				M[i][j] = 0;
		}
		M[i][i] = 0;
	}
}

void memPrint(double** &M, int** &P, const int n, bool printP) {
	cout << "Matrica M:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(4) << M[i][j];
		cout << endl;
	}
	if (!printP)
		return;
	cout << "Matrica P:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(4) << P[i][j];
		cout << endl;
	}
}

void memInit(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = 0;
}

void memEnd(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++) {
		delete[]M[i];
		delete[]P[i];
	}
	delete[]M;
	delete[]P;
}

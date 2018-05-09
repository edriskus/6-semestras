// MatDaug.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
#define _A(_i,_j) A[_i*N + _j]
#define _Ai(_j,_i) A[_i*N + _j]
#define myreal float 
int main()
{
	int N;
	myreal *A;
	myreal *X;
	myreal *Y;
	srand(5);
	for(N = 100; N<=1600; N = N * 2){

	A = new myreal[N*N];
	X = new myreal[N];
	Y = new myreal[N];
	for (int i = 0; i < N; i++) {
		X[i] = rand() % 1000 + 1;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		_A(i,j) = rand() % 1000 + 1;


	struct timeval start, end;
  	gettimeofday(&start, NULL);
	for (int i = 0; i < N; i++) {
		Y[i] = 0;
		for (int j = 0; j < N; j++) {
			Y[i] += X[j] * _A(i, j);
		}
	}
	gettimeofday(&end, NULL);
	myreal laikas = (myreal)((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/(myreal)1000000;
	myreal ops = 2*N*N; 
	cout<<"N = "<<N<<" : "<<laikas <<" : "<< ops/laikas  <<endl;
  	/*printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));*/
	delete [] A;
	delete [] X;
	delete [] Y;
	}

	return 0;
}


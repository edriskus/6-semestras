// OpenMPtest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
/*	omp_set_num_threads(3);
#pragma omp parallel
	{
		int size = omp_get_num_threads();
		int id = omp_get_thread_num();
		cout << "labas nuo "<< id << endl;
	}

	cout << "as jau vienas" << endl;*/
	int N = 1600;
	double *A = new double[N*N];
	double *B = new double[N*N];
	double *C = new double[N*N];
	//omp_set_num_threads(4);
#define _A(i,j) C[i*N+j]
#define _B(i,j) C[j*N+i]
#define _C(i,j) C[i*N+j]
	double t1 = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			_C(i, j) = 0;
			for (int k = 0; k < N; k++) {
				_C(i, j) += _A(i, k)*_B(k, j);
			}
		}
	}
	double t2 = omp_get_wtime();
	cout << "laikas : " << t2 - t1 << endl;
    return 0;
}


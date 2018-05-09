// GraphAlg.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
//#include <random>
#include <iostream>
#include <omp.h>
#include <iostream>
#include <iomanip>

using namespace std;

void memBegin(double** &M, int** &P, const int n);
void memGen(double** &M, int** &P, const int n);
void memPrint(double** &M, int** &P, const int n, bool printP = false);
void memInit(double** &M, int** &P, const int n);
void memEnd(double** &M, int** &P, const int n);

void printPath(int i, int j, int **P);

int main()
{
	double t1all = omp_get_wtime();

	double **D;
	int **P;
	int N;
	N = 10000;
	memBegin(D, P, N);
	srand(22); memGen(D, P, N);
	memInit(D, P, N);
	memPrint(D, P, N);
	
	double t1 = omp_get_wtime();
	
	#pragma omp parallel
	#pragma omp parallel for

	for (int k = 0; k < N; k++) {
		//sekancio ciklo veiksmai yra tarpusavyje nepriklausomi
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
	double t2 = omp_get_wtime();
	


	int v1 = 0;
	int v2 = N / 2;
	cout << "Trumpiausias atstumas nuo " << v1 << " iki " << v2 << " yra lygus " << D[v1][v2] << endl;
	cout << "Trumpiausias Kelias: ";
	cout << v1 << " -> "; printPath(v1, v2, P); cout << v2 << endl;
	memEnd(D, P, N);

	double t2all = omp_get_wtime();
	double laikas = t2 - t1;
	double laikasall = t2all - t1all;
	
	cout << "laikas " << laikas << endl;
	cout << "visas laikas" << laikasall <<endl;
	cout << "efektyvumas" << (laikas/laikasall)*100 <<"%"<<endl;
	

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

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
//#include <random>
#include <iostream>
#include <omp.h>
// #include <mpi.h>
#include <iostream>
#include <iomanip>

using namespace std;

void memBegin(double** &M, int** &P, const int n);
void memGen(double** &M, int** &P, const int n);
void memPrint(double** &M, int** &P, const int n, bool printP = false);
void memInit(double** &M, int** &P, const int n);
void memEnd(double** &M, int** &P, const int n);

void printPath(int i, int j, int **P);
int main_MPI(int argc, char *argv[]);
int main_omp(int matricosDydis);

int main(int argc, char *argv[])
{
	// omp_set_num_threads(1);
	cout << ">-----";
	for(int i = 100; i <= 2000; i+=100) {
		main_omp(i);
	}
	cout << "<" << endl;
}

/**
 * OpenMP algoritmo realizacija
 */
int main_omp(int matricosDydis)
{
	int N;		// Matricos dydis
	N = matricosDydis;
	
	int threadCount = 1;
	int chunkSize = N / threadCount;
	
	// Issaugom laika pries atminties priskyrima kintamiesiems
	double t1all = omp_get_wtime();
	double **D;	// Svoriu matrica
	int **P;	// Virsune, per kuria eis kelias

	memBegin(D, P, N);	// Priskiriam atminti
	srand(22); 			// Seedinam random
	memGen(D, P, N);	// Generuojam reiksmes
	memInit(D, P, N);	// Init P reiksmes
	
	// Issaugom laka pries algoritmo skaiciavimu dali
	double t1 = omp_get_wtime();
	
	{
		for (int k = 0; k < N; k++) {
			// Sekancio ciklo veiksmai yra tarpusavyje nepriklausomi
			// #pragma omp parallel 
			// #pragma omp for // schedule(dynamic, chunkSize)
			#pragma omp parallel for // schedule(dynamic)
			for (int i = 0; i < N; i++) {
				if (i != k){
					for (int j = 0; j < N; j++) {
						if (j != k && i != j && D[i][k] > 0 && D[k][j] > 0) {
							double d = D[i][k] + D[k][j];
							if (D[i][j] < 0 || d < D[i][j]) {
								D[i][j] = d;
								P[i][j] = k;
							}
						}	
					}
				}
			}
			// Pries vykdant sekancia iteracija reikia sinchronizuoti duomenis
		}
	}

	// Issaugom laika po skaiciavimu
	double t2 = omp_get_wtime();

	int v1 = 0;
	int v2 = N / 2;
	cout << endl << "Trumpiausias atstumas nuo " << v1 << " iki " << v2 << " yra lygus " << D[v1][v2] << endl;
	// cout << "Trumpiausias Kelias: ";
	// cout << v1 << " -> "; 
	// printPath(v1, v2, P); 
	// cout << v2 << endl;

	memEnd(D, P, N);

	double t2all = omp_get_wtime();
	double laikas = t2 - t1;
	double laikasall = t2all - t1all;
	
	cout << "N=" << N << ";";
	cout << "t=" << laikas << ";";
	cout << "T=" << laikasall << ";";
	cout << "d=" << (laikas/laikasall)*100 <<"%"<< endl;
	cout << "-----";
	
	return 0;
}

/**
 * Isvesti surasta kelia
 */
void printPath(int i, int j, int **P) {
	int k = P[i][j];
	if (k != -1) {
		printPath(i, k, P);
		cout << k << " -> ";
		printPath(k, j, P);
	}
}

/**
 * Priskirti atminti matricoms
 */
void memBegin(double** &M, int** &P, const int n) {
	M = new double*[n];
	P = new int*[n];
	for (int i = 0; i < n; i++) {
		M[i] = new double[n];
		P[i] = new int[n];
	}
}

/**
 * Uzpildyti M matricas random reiksmemis
 */
void memGen(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rand() % 2)
				M[i][j] = 1 + rand() % 100;
			else
				M[i][j] = -1;
		}
		M[i][i] = 0;
	}
}

/**
 * ISvesti i ekrana matricu turinius
 */
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

/**
 * Uzpildyti P matrica -1
 */
void memInit(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = -1;
}

/**
 * Isvalyti atminti, kuria uzima matricos
 */
void memEnd(double** &M, int** &P, const int n) {
	for (int i = 0; i < n; i++) {
		delete[]M[i];
		delete[]P[i];
	}
	delete[]M;
	delete[]P;
}

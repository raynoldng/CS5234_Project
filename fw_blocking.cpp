#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define INF 1e8
#define TEST_V 10
#define BASE 100 
// seems like BASE 100 is the best

typedef pair<int, int> ii;

int N;
// int arr[1024 * 1024];
int *arr;


inline int index(int r, int c) { return r*N + c; }

void FWI_FAST(int *A, int *B, int *C, const int s) {
	for(int k = 0; k < s; k++) {
		for(int i = 0; i < s; i++) {
			for(int j = 0; j < s; j++) {
				// A[index(i, j)] = min(A[index(i, j)],
				// 					 B[index(i, k)] + C[index(k, j)]);
				A[i*N+j] = min(A[i*N+j],
							   B[i*N+k]+C[k*N+j]);
			}
		}
	}
}

void FWR_FAST(int *A, int *B, int *C, const int s) {
	if(s <= BASE) {
		FWI_FAST(A, B, C, s);
		return;
	}

	int k = s / 2;
	// int *A11 = A, *A12 = A + k, *A21 = A + N*k, *A22 = A + N*k + k; 
	// int *B11 = B, *B12 = B + k, *B21 = B + N*k, *B22 = B + N*k + k; 
	// int *C11 = C, *C12 = C + k, *C21 = C + N*k, *C22 = C + N*k + k; 


	// FWR_FAST(A11, B11, C11, k);
	// FWR_FAST(A12, B11, C12, k);
	// FWR_FAST(A21, B21, C11, k);
	// FWR_FAST(A22, B21, C12, k);
	// FWR_FAST(A22, B22, C22, k);
	// FWR_FAST(A21, B22, C21, k);
	// FWR_FAST(A12, B12, C22, k);
	// FWR_FAST(A11, B12, C21, k);

	FWR_FAST(A, 			B, 				C, k);
	FWR_FAST(A + k, 		B, 				C + k, k);
	FWR_FAST(A + N*k, 		B + N*k, 		C, k);
	FWR_FAST(A + N*k + k,	B + N*k, 		C + k, k);
	FWR_FAST(A + N*k + k,	B + N*k + k, 	C + N*k + k, k);
	FWR_FAST(A + N*k, 		B + N*k + k, 	C + N*k, k);
	FWR_FAST(A + k, 		B + k, 			C + N*k + k, k);
	FWR_FAST(A, 			B + k, 			C + N*k, k);
}

int main() {
	scanf("%d", &N);
	int _N = 1;
	while(_N < N) _N <<= 1;
	N = _N;
	db(N);
	arr = new int[N*N];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			arr[index(i, j)] = INF;
	
	int u, v;
	// printf("Reading data\n");
	while(scanf(" %d %d", &u, &v) != EOF) {
		arr[index(u, v)] = arr[index(v, u)] = 1;
	}

	// printf("Running Floyd Warshall\n");

	time_t start = time(0);
	
	FWR_FAST(arr, arr, arr, N);

	double seconds_since_start = difftime( time(0), start);
	cout << "time: " << seconds_since_start << endl;

	// print out the first 10
	// for(int i = 0; i < min(N, TEST_V); i++) {
	// 	for(int j = 0; j < min(N, TEST_V); j++) {
	// 		printf("%d\t", arr[index(i, j)]);
	// 	}
	// 	printf("\n");
	// }

}
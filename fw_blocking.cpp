#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define INF 1e8
#define TEST_V 10
// #define BASE 32
int BASE = 2;
int N;
int *arr, *backup;

void copy() {
	for(int i = 0; i < N*N; i++) arr[i] = backup[i];
}


inline int index(int r, int c) { return r*N + c; }

void FWI_FAST(int *A, int *B, int *C, const int s) {
	// assert(A==B && A==C);
	for(int k = 0; k < s; k++) {
		for(int i = 0; i < s; i++) {
			for(int j = 0; j < s; j++) {
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

	FWR_FAST(A, 					B, 						C, (s/2));
	FWR_FAST(A + (s/2), 			B, 						C + (s/2), (s/2));
	FWR_FAST(A + N*(s/2), 			B + N*(s/2), 			C, (s/2));
	FWR_FAST(A + N*(s/2) + (s/2),	B + N*(s/2), 			C + (s/2), (s/2));
	FWR_FAST(A + N*(s/2) + (s/2),	B + N*(s/2) + (s/2), 	C + N*(s/2) + (s/2), (s/2));
	FWR_FAST(A + N*(s/2), 			B + N*(s/2) + (s/2), 	C + N*(s/2), (s/2));
	FWR_FAST(A + (s/2), 			B + (s/2), 				C + N*(s/2) + (s/2), (s/2));
	FWR_FAST(A, 					B + (s/2), 				C + N*(s/2), (s/2));
}

void run() {
	copy();
	cout << "Base: " << BASE << endl;
	time_t start = time(0);
	FWR_FAST(arr, arr, arr, N);
	double seconds_since_start = difftime( time(0), start);
	cout << "time: " << seconds_since_start << endl;
}

int main() {
	scanf("%d", &N);
	int _N = 1;
	while(_N < N) _N <<= 1;
	N = _N;
	db(N);
	arr = new int[N*N];
	backup = new int[N*N];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			backup[index(i, j)] = INF;
	
	int u, v;
	// printf("Reading data\n");
	while(scanf(" %d %d", &u, &v) != EOF) {
		backup[index(u, v)] = backup[index(v, u)] = 1;
	}

	// while(BASE <= 1024) {
	// 	run();
	// 	BASE = BASE * 2;
	// }

	BASE = 128;
	run();
	// cout << "time: " << seconds_since_start << endl;

	// print out the first 10
	// for(int i = 0; i < min(N, TEST_V); i++) {
	// 	for(int j = 0; j < min(N, TEST_V); j++) {
	// 		printf("%d\t", arr[index(i, j)]);
	// 	}
	// 	printf("\n");
	// }

}
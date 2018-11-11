#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define INF 1e8
#define TEST_V 10
#define BASE 256

typedef pair<int, int> ii;

int V;
int D[1024][1024];

void FWI(int ar, int ac, int br, int bc, int cr, int cc, int N) {
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				D[i+ar][j+ac] = min(D[i+ar][j+ac], 
									D[i+br][k+bc] + D[k+cr][j+cc]);

}

void FWR(int A1, int A2, int B1, int B2, int C1, int C2, int N) {
	// FWI(A1, A2, B1, B2, C1, C2, N);
	if(N <= BASE) FWI(A1, A2, B1, B2, C1, C2, N);
	else {
		int K = N/2;
		int A11_1 = A1, A11_2 = A2, A12_1 = A1, A12_2 = A2+K, A21_1 = A1+K, A21_2 = A2, A22_1 = A1+K, A22_2 = A2+K;
		int B11_1 = B1, B11_2 = B2, B12_1 = B1, B12_2 = B2+K, B21_1 = B1+K, B21_2 = B2, B22_1 = B1+K, B22_2 = B2+K;
		int C11_1 = C1, C11_2 = C2, C12_1 = C1, C12_2 = C2+K, C21_1 = C1+K, C21_2 = C2, C22_1 = C1+K, C22_2 = C2+K;

		FWR(A11_1, A11_2, B11_1, B11_2, C11_1, C11_2, K);
        FWR(A12_1, A12_2, B11_1, B11_2, C12_1, C12_2, K);
        FWR(A21_1, A21_2, B21_1, B21_2, C11_1, C11_2, K);
        FWR(A22_1, A22_2, B21_1, B21_2, C12_1, C12_2, K);
        FWR(A22_1, A22_2, B22_1, B22_2, C22_1, C22_2, K);
        FWR(A21_1, A21_2, B22_1, B22_2, C21_1, C21_2, K);
        FWR(A12_1, A12_2, B12_1, B12_2, C22_1, C22_2, K);
        FWR(A11_1, A11_2, B12_1, B12_2, C21_1, C21_2, K);		
	}
}


int main() {
	scanf("%d", &V);
	int _V = 1;
	while(_V < V) _V <<= 1;
	V = _V;
	db(V);

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			D[i][j] = INF;
	
	int u, v;
	printf("Reading data\n");
	while(scanf(" %d %d", &u, &v) != EOF) {
		D[u][v] = D[v][u] = 1;
	}

	printf("Running Floyd Warshall\n");
	FWR(0, 0, 0, 0, 0, 0, V);

	// print out the first 10
	for(int i = 0; i < TEST_V; i++) {
		for(int j = 0; j < TEST_V; j++) {
			printf("%d\t", D[i][j]);
		}
		printf("\n");
	}

}
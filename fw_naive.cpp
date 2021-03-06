#include <bits/stdc++.h>
#include <time.h>

using namespace std;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

#define INF 1e8
#define TEST_V 10

int V;
int dist[8192][8192];

int main() {
	scanf("%d", &V);

	// set to power of 2
	int _V = 1;
	while(_V < V) _V <<= 1;
	V = _V;
	db(V);
	// V = 10;
	// int **dist = new int*[V];
	// for(int i = 0; i < V; i++) dist[i] = new int[V];

	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			dist[i][j] = INF;
	
	int u, v;
	// printf("Reading data\n");
	while(scanf(" %d %d", &u, &v) != EOF) {
		dist[u][v] = dist[v][u] = 1;
	}

	
	time_t start = time(0);
	


	// printf("Running Floyd Warshall\n");
	for(int k = 0; k < V; k++) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				// dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	double seconds_since_start = difftime( time(0), start);
	// cout << "time: " << seconds_since_start << endl;
	printf("time: %f\n", seconds_since_start);
	// print out the first 10
	// for(int i = 0; i < TEST_V; i++) {
	// 	for(int j = 0; j < TEST_V; j++) {
	// 		printf("%d\t", dist[i][j]);
	// 	}
	// 	printf("\n");
	// }

}
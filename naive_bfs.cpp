#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adjlist;
int V;

void BFS(int u, vi& visited) {
	visited[u] = 1;

	list<int> Q;
	Q.push_back(u);

	while(!Q.empty()) {
		int s = Q.front(); Q.pop_front();
		visited[s] = 1;
		for(int v : adjlist[u]) {
			if(visited[v] == 0) {
				Q.push_back(v);
			}
		}
	}
}

int main() {
	scanf("%d", &V);
	adjlist = vvi(V, vi());
	int u, v;

	while(scanf(" %d %d", &u, &v) != EOF) {
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	// find size of CC at 1
	vi visited(V, 0);
	int nCCs = 0;
	for(int i = 0; i < V; i++) {
		if(visited[i] == 0) {
			nCCs++;
			BFS(i, visited);
		}
	}
	cout << "number of CCs: " << nCCs << endl;
}	
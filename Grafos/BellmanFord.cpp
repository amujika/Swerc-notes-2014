#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vi dist;
//SSSP from s, returns true if a negative cycle exist, this loop is not necessarily reachable from s
bool BellmanFord(vvi v, vvi w, int s) {
	n = v.size();
	dist = vi(n, 1e9);
	dist[s] = 0;
	for (int i = 0; i < n-1; ++i) {
		for (int u = 0; u < n; ++u) {
			for (int j = 0; j < v[u].size(); ++j) {
				dist[v[u][j]] = min(dist[v[u][j]], dist[u] + w[u][j]);
			}
		}
	}
	bool loop = false;
	for (int u = 0; u < n; ++u) {
		for (int j = 0; j < v[u].size(); ++j) {
			if (dist[v[u][j]] > dist[u] + w[u][j])
			loop = true;
		}
	}
	return loop;
}

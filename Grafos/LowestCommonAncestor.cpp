#include <vector>
using namespace std;
typedef vector<int> vi;

// Requires an RMQ implementation
class LCA {
	int idx;
	vector<vi> adj;
	vi Par, E, L, H;
	RMQ * rmq;
	void dfs(int cur, int depth, int parent) {
		Par[cur] = parent;
		H[cur] = idx;
		E[idx] = cur;
		L[idx++] = depth;
		for (int i = 0; i < (int) adj[cur].size(); i++) {
			if (Par[adj[cur][i]] == -1) {
				dfs(adj[cur][i], depth + 1, cur);
				E[idx] = cur;
				L[idx++] = depth;
			}
		}
	}
public:
	LCA(int N, vector<vi> adjlist) { // (# of nodes, adjacency list)
	  idx = 0;
	  adj = adjlist;
	  Par = vi(N, -1); // Root is its own parent
	  E = vi(2*N-1); // Nodes visited in an Euler tour
	  L = vi(2*N-1); // Levels of the nodes visited in the Euler tour
	  H = vi(N, -1); // H[i] = Index of the first occurrence of node i in E
	  dfs(0, 0, 0); // We assume that the root is at index 0
	  rmq = new RMQ(2*N-1, L);
	}
	int depth(int u) { return L[H[u]]; } // Depth of u
	int parent(int u) { return Par[u]; } // Parent of u
	int find(int u, int v) { // LCA(u, v)
		if (H[u] > H[v]) swap(u, v);
		return E[rmq->query(H[u], H[v])];
	}
};

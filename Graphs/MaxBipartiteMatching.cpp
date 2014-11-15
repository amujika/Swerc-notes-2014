// Maximum Cardinality Bipartite Matching
//  -- Representación con matriz de adyacencia
//  -- Pasar a la constructora el tamaño de las dos particiones (izquierda y derecha)
//  -- Añadir ejes con addEdge(origen, destino)
// La función getMatching devuelve la cardinalidad del matching, y rellena los vectores mr y mc:
//   mr[i] = nodo asignado al nodo izquierdo i
// 	 mc[j] = nodo asignado al nodo derecho j
// También es útil para:
//   Maximum Independent Set = |V| - MCBM
//	 Minimum Vertex Cover = MCBM
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class MCBM {
	int nLeft, nRight;
	vvi mat_adj;
	vi mr, mc;
	bool FindMatch(int i, const vvi &mat_adj, vi &seen) {
		for (int j = 0; j < nRight; j++) {
			if (mat_adj[i][j] && !seen[j]) {
				seen[j] = true;
				if (mc[j] < 0 || FindMatch(mc[j], mat_adj, seen)) {
					mr[i] = j; mc[j] = i; return true;
				}
			}
		}
		return false;
	}
public:
	MCBM(int NLeft, int NRight) : nLeft(NLeft), nRight(NRight), mr(NLeft, -1), mc(NRight, -1) {
		mat_adj = vvi(NLeft, vi(NRight));
	}
	void addEdge(int u, int v) { mat_adj[u][v] = 1; }
	int getMatching() {
		int ct = 0;
		for (int i = 0; i < nLeft; i++) {
			vi seen(nRight);
			if (FindMatch(i, mat_adj, seen)) ct++;
		}
		return ct;
	}
	vi getLeftMatches() { return mr; };
	vi getRightMatches() { return mc; };
};

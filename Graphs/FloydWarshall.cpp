// COMPLEXITY: O(V^3) (V < 400)
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// adj_mat = matriz de adyacencia del grafo
// adj_mat[i][j] = INF si no hay arista
// adj_mat[i][i] = 0
// V = cantidad de nodos
// Si despues de todo la diagonal tiene un valor menor que cero, tiene ciclos negativos
void FloydWarshall (vvi &adj_mat) {
	int V = adj_mat.size();
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
}

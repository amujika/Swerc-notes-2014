#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

class RMQ {
private:
	vi _A;
	vi logTable;
	vector<vi> SpT; // SpT[i][j] = RMQ of range starting at i and length (2^j)
public:
	RMQ(int N, vi A) {
		_A = A;
		logTable = vi(N + 1);
		for (int i = 2; i <= N; i++)
			logTable[i] = logTable[i >> 1] + 1;
		SpT = vector<vi>(N, vi(logTable[N] + 1));
		for (int i = 0; i < N; i++)
			SpT[i][0] = i;
		for (int j = 1; (1 << j) <= N; j++)
			for (int i = 0; i + (1 << j) - 1 < N; i++)
				if (_A[SpT[i][j - 1]] < _A[SpT[i + (1 << (j - 1))][j - 1]])
					SpT[i][j] = SpT[i][j - 1];
				else
					SpT[i][j] = SpT[i + (1 << (j - 1))][j - 1];
	}
	int query(int i, int j) {
		int k = logTable[j-i+1]; // 2^k <= (j-i+1)
		if (_A[SpT[i][k]] <= _A[SpT[j - (1 << k) + 1][k]])
			return SpT[i][k];
		else
			return SpT[j - (1 << k) + 1][k];
	}
};

// COMPLEXITY: O(sqrt(n))
#include <vector>

using namespace std;
typedef vector<int> vi;

//Returns a list of all the factors of n
//Example: n = 12 -> result = [2, 2, 3]
// n > 1
vi factors(int n)  {
	int z = 2;
	vi result;

	while (z * z <= n) {
		if (n % z == 0) {
			result.push_back(z);
			n /= z;
		} else {
			z++;
		}
	}
	if (n > 1)    	result.push_back(n);
	return result;
}

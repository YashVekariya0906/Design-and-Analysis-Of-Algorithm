#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrix_chain_multiply(vector<int> &dn, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int d = 1; d < n; d++) {
        for (int i = 1; i < n - d; i++) {
            int j = i + d;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int temp = m[i][k] + m[k + 1][j] + dn[i - 1] * dn[k] * dn[j];

                if (temp < m[i][j]) {
                    m[i][j] = temp;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    vector<int> dn = {3, 5, 2, 3, 4};
    int n = dn.size();

    cout << "Minimum number of multiplications is: "
         << matrix_chain_multiply(dn, n);

    return 0;
}

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function to check if (i, j) is a local maxima
bool isLocalMaxima(const vector<vector<int>> &a, int i, int j, int n, int m) {
    int value = a[i][j];
    if (i > 0 && a[i-1][j] >= value) return false;
    if (i < n-1 && a[i+1][j] >= value) return false;
    if (j > 0 && a[i][j-1] >= value) return false;
    if (j < m-1 && a[i][j+1] >= value) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m; // Read dimensions

        vector<vector<int>> a(n, vector<int>(m));
        // Read the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        bool foundLocalMaxima;
        do {
            foundLocalMaxima = false;
            int localMaxI = -1, localMaxJ = -1;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (isLocalMaxima(a, i, j, n, m)) {
                        if (localMaxI == -1 || i < localMaxI || (i == localMaxI && j < localMaxJ)) {
                            localMaxI = i;
                            localMaxJ = j;
                            foundLocalMaxima = true;
                        }
                    }
                }
            }

            if (foundLocalMaxima) {
                // Decrease the value of the identified local maxima
                a[localMaxI][localMaxJ] -= 1;
            }
        } while (foundLocalMaxima);

        // Output the stabilized matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

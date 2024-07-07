#include <iostream>

const int MOD = 1000000007;

// Function to calculate factorial modulo MOD
int factorialMod(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int n = 212; // The number for which factorial is to be calculated
    int result = factorialMod(n);
    std::cout << "212! % (10^9+7) = " << result << std::endl;
    return 0;
}

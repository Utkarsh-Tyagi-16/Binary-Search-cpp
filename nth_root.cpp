#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Computes base^exp, returns LLONG_MAX if result exceeds limit (to avoid overflow)
    long long cal(int base, int exp, int limit) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > limit) return LLONG_MAX;
        }
        return result;
    }

    // Returns x such that x^n == m, or -1 if no integer nth root exists
    int nthRoot(int n, int m) {
        int lo = 1, hi = m;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long power = cal(mid, n, m);

            if (power == m) return mid;       // exact nth root found
            else if (power < m) lo = mid + 1; // mid^n too small, go right
            else hi = mid - 1;                // mid^n too large, go left
        }

        return -1; // no integer nth root
    }
};

int main() {
    Solution sol;

    // Test case 1: Perfect cube root
    cout << "Test 1: " << 3 << "th root of " << 27 << endl;
    cout << "Result: " << sol.nthRoot(3, 27) << endl; // Expected: 3
    cout << endl;

    // Test case 2: Perfect square root
    cout << "Test 2: " << 2 << "th root of " << 25 << endl;
    cout << "Result: " << sol.nthRoot(2, 25) << endl; // Expected: 5
    cout << endl;

    // Test case 3: No perfect nth root
    cout << "Test 3: " << 3 << "th root of " << 20 << endl;
    cout << "Result: " << sol.nthRoot(3, 20) << endl; // Expected: -1
    cout << endl;

    // Test case 4: 4th root
    cout << "Test 4: " << 4 << "th root of " << 81 << endl;
    cout << "Result: " << sol.nthRoot(4, 81) << endl; // Expected: 3
    cout << endl;

    // Test case 5: 1st root (always m itself)
    cout << "Test 5: " << 1 << "th root of " << 10 << endl;
    cout << "Result: " << sol.nthRoot(1, 10) << endl; // Expected: 10
    cout << endl;

    // Test case 6: 5th root
    cout << "Test 6: " << 5 << "th root of " << 32 << endl;
    cout << "Result: " << sol.nthRoot(5, 32) << endl; // Expected: 2
    cout << endl;

    // Test case 7: No perfect root
    cout << "Test 7: " << 2 << "th root of " << 14 << endl;
    cout << "Result: " << sol.nthRoot(2, 14) << endl; // Expected: -1
    cout << endl;

    return 0;
}

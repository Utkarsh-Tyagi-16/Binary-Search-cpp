#include <iostream>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;

        int low = 1;
        int high = n;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;

            if (val <= n) {
                low = mid + 1;  // mid could be answer, try for larger
            } else {
                high = mid - 1; // mid is too large
            }
        }

        // high is the floor of sqrt(n)
        return high;
    }
};

int main() {
    Solution sol;

    // Test case 1: Perfect square
    cout << "Test 1: n = 25" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(25) << endl; // Expected: 5
    cout << endl;

    // Test case 2: Non-perfect square
    cout << "Test 2: n = 35" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(35) << endl; // Expected: 5
    cout << endl;

    // Test case 3: Perfect square
    cout << "Test 3: n = 49" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(49) << endl; // Expected: 7
    cout << endl;

    // Test case 4: Non-perfect square
    cout << "Test 4: n = 10" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(10) << endl; // Expected: 3
    cout << endl;

    // Test case 5: Edge case n = 0
    cout << "Test 5: n = 0" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(0) << endl; // Expected: 0
    cout << endl;

    // Test case 6: Edge case n = 1
    cout << "Test 6: n = 1" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(1) << endl; // Expected: 1
    cout << endl;

    // Test case 7: Large number
    cout << "Test 7: n = 100" << endl;
    cout << "Floor Sqrt: " << sol.floorSqrt(100) << endl; // Expected: 10
    cout << endl;

    return 0;
}

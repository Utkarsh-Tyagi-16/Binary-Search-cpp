#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    // Returns sum of ceil(num / div) for all elements
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    // Returns smallest divisor such that sum of ceil(arr[i]/div) <= threshold
    int smallestDivisor(vector<int>& arr, int threshold) {
        if ((int)arr.size() > threshold) return -1; // even divisor = max can't help

        int low  = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sumByD(arr, mid) <= threshold) {
                high = mid - 1; // mid works, try smaller divisor
            } else {
                low = mid + 1;  // sum too large, increase divisor
            }
        }

        return low;
    }
};

int main() {
    Solution sol;

    // Test case 1: From LeetCode example
    vector<int> arr1 = {1, 2, 5, 9};
    cout << "Test 1: arr = [1, 2, 5, 9], threshold = 6" << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr1, 6) << endl; // Expected: 5
    cout << endl;

    // Test case 2: From LeetCode example
    vector<int> arr2 = {44, 22, 33, 11, 1};
    cout << "Test 2: arr = [44, 22, 33, 11, 1], threshold = 5" << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr2, 5) << endl; // Expected: 44
    cout << endl;

    // Test case 3: Divisor of 1 works (sum already within threshold)
    vector<int> arr3 = {1, 1, 1, 1};
    cout << "Test 3: arr = [1, 1, 1, 1], threshold = 4" << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr3, 4) << endl; // Expected: 1
    cout << endl;

    // Test case 4: Large values, tight threshold
    vector<int> arr4 = {100, 200, 300};
    cout << "Test 4: arr = [100, 200, 300], threshold = 3" << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr4, 3) << endl; // Expected: 300
    cout << endl;

    // Test case 5: Impossible — array size > threshold
    vector<int> arr5 = {1, 2, 3, 4, 5};
    cout << "Test 5: arr = [1, 2, 3, 4, 5], threshold = 4" << endl;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr5, 4) << endl; // Expected: -1
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the number of times a sorted array has been rotated.
    // Key Insight: The index of the minimum element = number of rotations.
    //   e.g., [4, 5, 6, 7, 0, 1, 2] -> min is at index 4 -> rotated 4 times.
    int findRotations(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2; // Avoids integer overflow

            // If mid element is greater than the rightmost element,
            // the minimum (and thus the rotation point) is in the RIGHT half
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // Otherwise, the minimum is at mid or in the LEFT half
            else {
                high = mid; // Keep mid as a candidate
            }
        }

        // low == high, pointing to the index of the minimum element.
        // This index is exactly the number of rotations.
        return low;
    }
};

int main() {
    Solution sol;

    // Example 1: Rotated 4 times → min element 0 is at index 4
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Array: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Rotations: " << sol.findRotations(arr1) << endl; // Expected: 4
    cout << endl;

    // Example 2: Rotated 3 times → min element 1 is at index 3
    vector<int> arr2 = {4, 5, 6, 1, 2, 3};
    cout << "Array: [4, 5, 6, 1, 2, 3]" << endl;
    cout << "Rotations: " << sol.findRotations(arr2) << endl; // Expected: 3
    cout << endl;

    // Example 3: Not rotated (or rotated n times) → min is at index 0
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Array: [1, 2, 3, 4, 5]" << endl;
    cout << "Rotations: " << sol.findRotations(arr3) << endl; // Expected: 0
    cout << endl;

    // Example 4: Rotated 4 times → min element 0 is at index 4
    vector<int> arr4 = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Array: [4, 5, 6, 7, 0, 1, 2, 3]" << endl;
    cout << "Rotations: " << sol.findRotations(arr4) << endl; // Expected: 4
    cout << endl;

    // Example 5: Single element → rotated 0 times
    vector<int> arr5 = {3};
    cout << "Array: [3]" << endl;
    cout << "Rotations: " << sol.findRotations(arr5) << endl; // Expected: 0

    return 0;
}

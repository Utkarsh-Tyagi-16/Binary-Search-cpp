#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum element in a rotated sorted array.
    // The array was originally sorted in ascending order, then rotated at some pivot.
    // Uses binary search for O(log n) time complexity.
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2; // Avoids integer overflow

            // If mid element is greater than the rightmost element,
            // the minimum must be in the RIGHT half (after mid).
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            }
            // Otherwise, the left half (including mid) contains the minimum.
            // We keep mid as a candidate by setting high = mid (not mid - 1).
            else {
                high = mid;
            }
        }

        // low == high, pointing to the minimum element
        return arr[low];
    }
};

int main() {
    Solution sol;

    // Example 1: Array rotated at index 4
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Array: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Minimum: " << sol.findMin(arr1) << endl; // Expected: 0
    cout << endl;

    // Example 2: Array rotated at index 1
    vector<int> arr2 = {3, 1, 2};
    cout << "Array: [3, 1, 2]" << endl;
    cout << "Minimum: " << sol.findMin(arr2) << endl; // Expected: 1
    cout << endl;

    // Example 3: Array not rotated (already sorted)
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Array: [1, 2, 3, 4, 5]" << endl;
    cout << "Minimum: " << sol.findMin(arr3) << endl; // Expected: 1
    cout << endl;

    // Example 4: Single element array
    vector<int> arr4 = {7};
    cout << "Array: [7]" << endl;
    cout << "Minimum: " << sol.findMin(arr4) << endl; // Expected: 7
    cout << endl;

    // Example 5: Two element array, rotated
    vector<int> arr5 = {2, 1};
    cout << "Array: [2, 1]" << endl;
    cout << "Minimum: " << sol.findMin(arr5) << endl; // Expected: 1

    return 0;
}

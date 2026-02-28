#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for element k in a rotated sorted array that may contain duplicates.
    // Returns true if k exists in the array, false otherwise.
    bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If mid element is the target, return true
            if (arr[mid] == k) return true;

            // Edge case with duplicates:
            // If arr[low], arr[mid], and arr[high] are all equal,
            // we cannot determine which half is sorted.
            // Shrink both ends and continue.
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // Check if the LEFT half (low to mid) is sorted
            if (arr[low] <= arr[mid]) {
                // Target lies within the sorted left half
                if (arr[low] <= k && k <= arr[mid]) {
                    high = mid - 1; // Eliminate the right half
                } else {
                    low = mid + 1;  // Eliminate the left half
                }
            }
            // Otherwise, the RIGHT half (mid to high) must be sorted
            else {
                // Target lies within the sorted right half
                if (arr[mid] <= k && k <= arr[high]) {
                    low = mid + 1;  // Eliminate the left half
                } else {
                    high = mid - 1; // Eliminate the right half
                }
            }
        }

        // Target not found
        return false;
    }
};

int main() {
    Solution sol;

    // Example 1: Target exists, array has duplicates
    vector<int> arr1 = {2, 5, 6, 0, 0, 1, 2};
    int k1 = 0;
    cout << "Array: [2, 5, 6, 0, 0, 1, 2]" << endl;
    cout << "Target: " << k1 << endl;
    cout << "Found: " << (sol.search(arr1, k1) ? "true" : "false") << endl; // Expected: true
    cout << endl;

    // Example 2: Target does not exist, array has duplicates
    vector<int> arr2 = {2, 5, 6, 0, 0, 1, 2};
    int k2 = 3;
    cout << "Array: [2, 5, 6, 0, 0, 1, 2]" << endl;
    cout << "Target: " << k2 << endl;
    cout << "Found: " << (sol.search(arr2, k2) ? "true" : "false") << endl; // Expected: false
    cout << endl;

    // Example 3: All duplicate elements
    vector<int> arr3 = {1, 1, 1, 1, 1};
    int k3 = 1;
    cout << "Array: [1, 1, 1, 1, 1]" << endl;
    cout << "Target: " << k3 << endl;
    cout << "Found: " << (sol.search(arr3, k3) ? "true" : "false") << endl; // Expected: true
    cout << endl;

    // Example 4: Single element, target not found
    vector<int> arr4 = {3};
    int k4 = 5;
    cout << "Array: [3]" << endl;
    cout << "Target: " << k4 << endl;
    cout << "Found: " << (sol.search(arr4, k4) ? "true" : "false") << endl; // Expected: false

    return 0;
}

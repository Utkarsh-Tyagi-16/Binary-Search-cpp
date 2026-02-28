#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for a target in a rotated sorted array.
    // Returns the index of the target if found, otherwise returns -1.
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If mid element is the target, return its index
            if (arr[mid] == target) return mid;

            // Check if the LEFT half (low to mid) is sorted
            if (arr[low] <= arr[mid]) {
                // Target lies within the sorted left half
                if (arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1; // Eliminate the right half
                } else {
                    low = mid + 1;  // Eliminate the left half
                }
            }
            // Otherwise, the RIGHT half (mid to high) must be sorted
            else {
                // Target lies within the sorted right half
                if (arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;  // Eliminate the left half
                } else {
                    high = mid - 1; // Eliminate the right half
                }
            }
        }

        // Target not found
        return -1;
    }
};

int main() {
    Solution sol;

    // Example 1: Array rotated at index 3
    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Target: " << target1 << endl;
    cout << "Index: " << sol.search(arr1, target1) << endl; // Expected: 4
    cout << endl;

    // Example 2: Target not present in the array
    vector<int> arr2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Array: [4, 5, 6, 7, 0, 1, 2]" << endl;
    cout << "Target: " << target2 << endl;
    cout << "Index: " << sol.search(arr2, target2) << endl; // Expected: -1
    cout << endl;

    // Example 3: Single element array
    vector<int> arr3 = {1};
    int target3 = 0;
    cout << "Array: [1]" << endl;
    cout << "Target: " << target3 << endl;
    cout << "Index: " << sol.search(arr3, target3) << endl; // Expected: -1

    return 0;
}

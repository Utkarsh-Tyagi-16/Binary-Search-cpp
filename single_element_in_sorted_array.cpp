#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the single non-duplicate element in a sorted array
    // where every other element appears exactly twice.
    // Uses binary search for O(log n) time complexity.
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        // Edge case: only one element in the array
        if (n == 1) return arr[0];

        // If the first element is unique (doesn't match its neighbor)
        if (arr[0] != arr[1]) return arr[0];

        // If the last element is unique (doesn't match its neighbor)
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        // Search within the range [1, n-2] since edges are already handled
        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If arr[mid] doesn't match either neighbor, it's the single element
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            // Key Observation:
            // In a normal pair sequence (before the single element),
            //   pairs start at EVEN indices: (0,1), (2,3), (4,5)...
            // After the single element, pairs shift to ODD indices.
            //
            // So if mid is ODD and pairs with mid-1 → we are in the LEFT (normal) half
            //    if mid is EVEN and pairs with mid+1 → we are in the LEFT (normal) half
            // In both cases, the single element lies to the RIGHT → move low up.
            if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) ||
                (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                low = mid + 1; // Single element is in the right half
            } else {
                high = mid - 1; // Single element is in the left half
            }
        }

        return -1; // Should never reach here for a valid input
    }
};

int main() {
    Solution sol;

    // Example 1: Single element in the middle
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Array: [1, 1, 2, 3, 3, 4, 4, 8, 8]" << endl;
    cout << "Single element: " << sol.singleNonDuplicate(arr1) << endl; // Expected: 2
    cout << endl;

    // Example 2: Single element at the end
    vector<int> arr2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Array: [3, 3, 7, 7, 10, 11, 11]" << endl;
    cout << "Single element: " << sol.singleNonDuplicate(arr2) << endl; // Expected: 10
    cout << endl;

    // Example 3: Single element at the beginning
    vector<int> arr3 = {1, 2, 2, 3, 3, 4, 4};
    cout << "Array: [1, 2, 2, 3, 3, 4, 4]" << endl;
    cout << "Single element: " << sol.singleNonDuplicate(arr3) << endl; // Expected: 1
    cout << endl;

    // Example 4: Only one element in the array
    vector<int> arr4 = {5};
    cout << "Array: [5]" << endl;
    cout << "Single element: " << sol.singleNonDuplicate(arr4) << endl; // Expected: 5

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Number of missing positives before arr[mid]
            // arr[mid] would be (mid+1) if no numbers were missing
            // so missing count = arr[mid] - (mid + 1)
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;  // kth missing is to the right
            } else {
                high = mid - 1; // kth missing is to the left
            }
        }

        // Answer = k + high + 1
        // high + 1 accounts for the elements in arr that are <= answer
        return k + high + 1;
    }
};

int main() {
    Solution sol;

    // Test case 1: From LeetCode example
    vector<int> arr1 = {2, 3, 4, 7, 11};
    cout << "Test 1: arr = [2, 3, 4, 7, 11], k = 5" << endl;
    cout << "Kth Missing: " << sol.findKthPositive(arr1, 5) << endl; // Expected: 9
    cout << endl;

    // Test case 2: From LeetCode example
    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Test 2: arr = [1, 2, 3, 4], k = 2" << endl;
    cout << "Kth Missing: " << sol.findKthPositive(arr2, 2) << endl; // Expected: 6
    cout << endl;

    // Test case 3: Missing number at beginning
    vector<int> arr3 = {2, 3, 4, 5, 6};
    cout << "Test 3: arr = [2, 3, 4, 5, 6], k = 1" << endl;
    cout << "Kth Missing: " << sol.findKthPositive(arr3, 1) << endl; // Expected: 1
    cout << endl;

    // Test case 4: Large k, missing falls beyond array
    vector<int> arr4 = {1, 2, 3};
    cout << "Test 4: arr = [1, 2, 3], k = 5" << endl;
    cout << "Kth Missing: " << sol.findKthPositive(arr4, 5) << endl; // Expected: 8
    cout << endl;

    // Test case 5: Single element
    vector<int> arr5 = {5};
    cout << "Test 5: arr = [5], k = 3" << endl;
    cout << "Kth Missing: " << sol.findKthPositive(arr5, 3) << endl; // Expected: 3
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        // Single element is always a peak
        if (n == 1) return 0;

        // Check if the first element is a peak
        if (arr[0] > arr[1]) return 0;

        // Check if the last element is a peak
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        // Search in the middle portion
        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            // mid is a peak if greater than both neighbours
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // If left neighbour is smaller, peak lies to the right
            else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1;
            }
            // If right neighbour is smaller, peak lies to the left
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Test case 1: Peak in the middle
    vector<int> arr1 = {1, 2, 3, 1};
    cout << "Test 1: [1, 2, 3, 1]" << endl;
    cout << "Peak index: " << sol.findPeakElement(arr1) << endl;
    cout << "Peak value: " << arr1[sol.findPeakElement(arr1)] << endl;
    cout << endl;

    // Test case 2: Multiple peaks, any valid one is acceptable
    vector<int> arr2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Test 2: [1, 2, 1, 3, 5, 6, 4]" << endl;
    cout << "Peak index: " << sol.findPeakElement(arr2) << endl;
    cout << "Peak value: " << arr2[sol.findPeakElement(arr2)] << endl;
    cout << endl;

    // Test case 3: Peak at the beginning
    vector<int> arr3 = {10, 5, 2, 1};
    cout << "Test 3: [10, 5, 2, 1]" << endl;
    cout << "Peak index: " << sol.findPeakElement(arr3) << endl;
    cout << "Peak value: " << arr3[sol.findPeakElement(arr3)] << endl;
    cout << endl;

    // Test case 4: Peak at the end
    vector<int> arr4 = {1, 2, 3, 4, 10};
    cout << "Test 4: [1, 2, 3, 4, 10]" << endl;
    cout << "Peak index: " << sol.findPeakElement(arr4) << endl;
    cout << "Peak value: " << arr4[sol.findPeakElement(arr4)] << endl;
    cout << endl;

    // Test case 5: Single element
    vector<int> arr5 = {42};
    cout << "Test 5: [42]" << endl;
    cout << "Peak index: " << sol.findPeakElement(arr5) << endl;
    cout << "Peak value: " << arr5[sol.findPeakElement(arr5)] << endl;
    cout << endl;

    return 0;
}

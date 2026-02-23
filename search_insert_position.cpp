#include<bits/stdc++.h>
using namespace std;

// Search Insert Position:
// If target exists, return its index.
// If target does not exist, return the index where it should be inserted
// so the array remains sorted. This is the same as Lower Bound.
int searchInsertPosition(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = arr.size(); // default insert position: end of array

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;      // target found, return its index
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // target is in the right half
        }
        else {
            result = mid;    // mid is a potential insert position
            right = mid - 1; // try to find a smaller valid position
        }
    }

    return result; // insert position if target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 6, 9, 11};

    int target1 = 5;  // exists in array
    int target2 = 4;  // does not exist in array

    cout << "Insert position of " << target1 << ": " << searchInsertPosition(arr, target1) << endl;
    cout << "Insert position of " << target2 << ": " << searchInsertPosition(arr, target2) << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// Floor: returns the largest element in the array that is <= target
// Returns -1 if all elements are greater than target
int floor(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; // -1 means no floor exists

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid]; // exact match is the floor
        }
        else if (arr[mid] < target) {
            result = arr[mid]; // arr[mid] is a valid floor candidate
            left = mid + 1;    // try to find a larger valid floor
        }
        else {
            right = mid - 1;   // arr[mid] > target, discard right half
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    int target1 = 6;  // floor should be 5
    int target2 = 0;  // no floor exists (all elements > 0)
    int target3 = 9;  // exact match

    cout << "Floor of " << target1 << ": " << floor(arr, target1) << endl;
    cout << "Floor of " << target2 << ": " << floor(arr, target2) << endl;
    cout << "Floor of " << target3 << ": " << floor(arr, target3) << endl;

    return 0;
}

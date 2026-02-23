#include<bits/stdc++.h>
using namespace std;

// Ceil: returns the smallest element in the array that is >= target
// Returns -1 if all elements are smaller than target
int ceil(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1; // -1 means no ceil exists

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid]; // exact match is the ceil
        }
        else if (arr[mid] > target) {
            result = arr[mid]; // arr[mid] is a valid ceil candidate
            right = mid - 1;   // try to find a smaller valid ceil
        }
        else {
            left = mid + 1;    // arr[mid] < target, discard left half
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    int target1 = 6;   // ceil should be 7
    int target2 = 14;  // no ceil exists (all elements < 14)
    int target3 = 5;   // exact match

    cout << "Ceil of " << target1 << ": " << ceil(arr, target1) << endl;
    cout << "Ceil of " << target2 << ": " << ceil(arr, target2) << endl;
    cout << "Ceil of " << target3 << ": " << ceil(arr, target3) << endl;

    return 0;
}

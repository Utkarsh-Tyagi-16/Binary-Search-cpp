#include<bits/stdc++.h>
using namespace std;

// Upper Bound: returns the index of the first element strictly > target
// If all elements are <= target, returns n (size of array)
int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();  // right is n, not n-1 (answer could be n)
    int result = arr.size(); // default: target is >= all elements

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) {
            result = mid;    // mid is a valid candidate, try to go left
            right = mid;
        } else {
            left = mid + 1;  // arr[mid] <= target, discard left half
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    int target = 7;
    int index = upperBound(arr, target);

    if (index < arr.size())
        cout << "Upper Bound of " << target << " is at index " << index << " (value: " << arr[index] << ")" << endl;
    else
        cout << "All elements are <= " << target << endl;

    return 0;
}

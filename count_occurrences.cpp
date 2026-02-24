#include<bits/stdc++.h>
using namespace std;

// Finds the FIRST index where target k appears
// Returns -1 if not found
int firstOccurrence(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;     // possible answer, look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1;   // target is in the right half
        }
        else {
            high = mid - 1;  // target is in the left half
        }
    }
    return first;
}

// Finds the LAST index where target k appears
// Returns -1 if not found
int lastOccurrence(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;     // possible answer, look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1;   // target is in the right half
        }
        else {
            high = mid - 1;  // target is in the left half
        }
    }
    return last;
}

// Returns {first, last} position of k in the array
// Returns {-1, -1} if k doesn't exist
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return {-1, -1}; // k not present at all
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

// Count total occurrences of x using first and last position
// Formula: last - first + 1
int countOccurrences(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0; // x not found
    return (ans.second - ans.first + 1);
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8;

    int x1 = 8;
    cout << "Array: [2, 4, 6, 8, 8, 8, 11, 13]" << endl;
    cout << "Number of occurrences of " << x1 << ": " << countOccurrences(arr, n, x1) << endl;

    int x2 = 5; // not present
    cout << "Number of occurrences of " << x2 << ": " << countOccurrences(arr, n, x2) << endl;

    int x3 = 2; // appears once
    cout << "Number of occurrences of " << x3 << ": " << countOccurrences(arr, n, x3) << endl;

    return 0;
}

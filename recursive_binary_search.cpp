#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int target, int left, int right) {
    if (left > right) 
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) 
    {
        return mid;
    } 
    else if (arr[mid] < target)
    {
        return binarySearch(arr, target, mid + 1, right);
    } 
    else 
    {
        return binarySearch(arr, target, left, mid - 1);
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 67, 90};
    int target = 23;

    int result = binarySearch(arr, target, 0, arr.size() - 1);

    if (result != -1) 
    {
        cout << "Element found at index: " << result << endl;
    } 
    else 
    {
        cout << "Element not found." << endl;
    }

    return 0;
}

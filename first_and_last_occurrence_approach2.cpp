#include<bits/stdc++.h>
using namespace std;

// Finds the FIRST index where target appears
// If not found, returns -1
int findFirst(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1; // -1 means target not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;    // found a valid index, but keep searching left
            right = mid - 1; // move left to find an earlier occurrence
        }
        else if (nums[mid] < target) {
            left = mid + 1;  // target is in the right half
        }
        else {
            right = mid - 1; // target is in the left half
        }
    }

    return result;
}

// Finds the LAST index where target appears
// If not found, returns -1
int findLast(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int result = -1; // -1 means target not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;    // found a valid index, but keep searching right
            left = mid + 1;  // move right to find a later occurrence
        }
        else if (nums[mid] < target) {
            left = mid + 1;  // target is in the right half
        }
        else {
            right = mid - 1; // target is in the left half
        }
    }

    return result;
}

// Combines both to return [first, last] occurrence
vector<int> searchRange(vector<int>& nums, int target) {
    return { findFirst(nums, target), findLast(nums, target) };
}

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> res1 = searchRange(nums1, target1);
    cout << "Array: [5, 7, 7, 8, 8, 10], Target: " << target1 << endl;
    cout << "First occurrence: " << res1[0] << ", Last occurrence: " << res1[1] << endl;

    cout << endl;

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> res2 = searchRange(nums2, target2);
    cout << "Array: [5, 7, 7, 8, 8, 10], Target: " << target2 << endl;
    cout << "First occurrence: " << res2[0] << ", Last occurrence: " << res2[1] << endl;

    cout << endl;

    vector<int> nums3 = {1, 1, 1, 1, 1};
    int target3 = 1;
    vector<int> res3 = searchRange(nums3, target3);
    cout << "Array: [1, 1, 1, 1, 1], Target: " << target3 << endl;
    cout << "First occurrence: " << res3[0] << ", Last occurrence: " << res3[1] << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using STL lower_bound and upper_bound
// lower_bound returns iterator to first element >= target
// upper_bound returns iterator to first element > target
// So: first occurrence = lower_bound position
//     last occurrence  = upper_bound position - 1

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);

    if (nums.empty()) return ans;

    // Find first occurrence: first index where nums[i] >= target
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    // If lb is out of bounds or element at lb is not the target, target doesn't exist
    if (lb == nums.size() || nums[lb] != target) return ans;

    // Find last occurrence: upper_bound gives first index > target, so subtract 1
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    ans[0] = lb; // first occurrence
    ans[1] = ub; // last occurrence

    return ans;
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

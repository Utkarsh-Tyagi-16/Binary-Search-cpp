#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if it's possible to split the array into at most k parts
    // such that no part has a sum greater than 'target'
    bool isPossible(vector<int>& nums, int k, int target)
    {
        int numpart = 1;   // Start with 1 partition
        int current = 0;   // Running sum of current partition

        for (int i = 0; i < nums.size(); i++)
        {
            // If a single element exceeds the target, it's impossible
            if (nums[i] > target)
            {
                return false;
            }
            // If adding this element stays within the target, add it
            if (nums[i] + current <= target)
            {
                current += nums[i];
            }
            // Otherwise, start a new partition
            else
            {
                current = nums[i];
                numpart++;
            }
        }
        // Feasible if we used at most k partitions
        return numpart <= k;
    }

    // Binary search on the answer: the minimized largest sum
    int splitArray(vector<int>& nums, int k)
    {
        // low = 0, high = INT_MAX (search the full range)
        int low = 0;
        int high = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If we can split with max sum = mid, try smaller
            if (isPossible(nums, k, mid))
            {
                high = mid - 1;
            }
            // Otherwise, we need a larger max sum
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;

    // Test Case 1: [7,2,5,10,8], k=2 -> Output: 18
    // Split: [7,2,5] and [10,8] => sums are 14 and 18 => max = 18
    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << "Test 1: " << sol.splitArray(nums1, 2) << endl; // 18

    // Test Case 2: [1,2,3,4,5], k=2 -> Output: 9
    // Split: [1,2,3,4] and [5] => sums are 10 and 5, but optimal is [1,2,3] [4,5] => 6 and 9 => max = 9
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << sol.splitArray(nums2, 2) << endl; // 9

    // Test Case 3: [1,4,4], k=3 -> Output: 4
    // Each element is its own partition => max = 4
    vector<int> nums3 = {1, 4, 4};
    cout << "Test 3: " << sol.splitArray(nums3, 3) << endl; // 4

    // Test Case 4: Single element
    vector<int> nums4 = {10};
    cout << "Test 4: " << sol.splitArray(nums4, 1) << endl; // 10

    return 0;
}

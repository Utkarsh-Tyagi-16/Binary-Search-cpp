#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Returns the maximum pile size (upper bound for binary search)
    int find_max(vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    // Returns total hours needed to eat all piles at speed 'hour'
    long long function(vector<int>& piles, int hour) {
        long long totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += (piles[i] + hour - 1) / hour; // ceil division
        }
        return totalH;
    }

    // Returns minimum eating speed to finish all piles within h hours
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = find_max(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = function(piles, mid);

            if (totalH <= h) {
                high = mid - 1; // mid works, try smaller speed
            } else {
                low = mid + 1;  // mid too slow, increase speed
            }
        }

        return low; // smallest valid speed
    }
};

int main() {
    Solution sol;

    // Test case 1: From LeetCode example
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test 1: piles = [3, 6, 7, 11], h = 8" << endl;
    cout << "Min Speed: " << sol.minEatingSpeed(piles1, h1) << endl; // Expected: 4
    cout << endl;

    // Test case 2: From LeetCode example
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test 2: piles = [30, 11, 23, 4, 20], h = 5" << endl;
    cout << "Min Speed: " << sol.minEatingSpeed(piles2, h2) << endl; // Expected: 30
    cout << endl;

    // Test case 3: From LeetCode example
    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Test 3: piles = [30, 11, 23, 4, 20], h = 6" << endl;
    cout << "Min Speed: " << sol.minEatingSpeed(piles3, h3) << endl; // Expected: 23
    cout << endl;

    // Test case 4: Single pile
    vector<int> piles4 = {10};
    int h4 = 4;
    cout << "Test 4: piles = [10], h = 4" << endl;
    cout << "Min Speed: " << sol.minEatingSpeed(piles4, h4) << endl; // Expected: 3
    cout << endl;

    // Test case 5: Already fast enough at speed 1
    vector<int> piles5 = {1, 1, 1, 1};
    int h5 = 10;
    cout << "Test 5: piles = [1, 1, 1, 1], h = 10" << endl;
    cout << "Min Speed: " << sol.minEatingSpeed(piles5, h5) << endl; // Expected: 1
    cout << endl;

    return 0;
}

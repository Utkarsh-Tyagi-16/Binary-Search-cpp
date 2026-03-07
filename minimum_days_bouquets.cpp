#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Checks if we can make m bouquets of k consecutive flowers by 'day'
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;               // flower has bloomed, count it
                if (cnt == k) {
                    bouquets++;      // formed one bouquet of k consecutive flowers
                    cnt = 0;         // reset for next bouquet
                }
            } else {
                cnt = 0;             // chain broken, reset count
            }
        }
        return bouquets >= m;
    }

    // Returns minimum day to make m bouquets, each needing k consecutive flowers
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > (long long)bloomDay.size()) return -1; // impossible

        int low  = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans  = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans  = mid;      // mid works, try earlier day
                high = mid - 1;
            } else {
                low = mid + 1;   // mid not enough, try later day
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1: From LeetCode example
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    cout << "Test 1: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 1" << endl;
    cout << "Min Days: " << sol.minDays(bloomDay1, 3, 1) << endl; // Expected: 3
    cout << endl;

    // Test case 2: From LeetCode example
    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    cout << "Test 2: bloomDay = [1, 10, 3, 10, 2], m = 3, k = 2" << endl;
    cout << "Min Days: " << sol.minDays(bloomDay2, 3, 2) << endl; // Expected: -1
    cout << endl;

    // Test case 3: From LeetCode example
    vector<int> bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
    cout << "Test 3: bloomDay = [7, 7, 7, 7, 12, 7, 7], m = 2, k = 3" << endl;
    cout << "Min Days: " << sol.minDays(bloomDay3, 2, 3) << endl; // Expected: 12
    cout << endl;

    // Test case 4: All bloom on same day
    vector<int> bloomDay4 = {5, 5, 5, 5, 5};
    cout << "Test 4: bloomDay = [5, 5, 5, 5, 5], m = 1, k = 5" << endl;
    cout << "Min Days: " << sol.minDays(bloomDay4, 1, 5) << endl; // Expected: 5
    cout << endl;

    // Test case 5: Not enough flowers
    vector<int> bloomDay5 = {1, 2, 3};
    cout << "Test 5: bloomDay = [1, 2, 3], m = 2, k = 2" << endl;
    cout << "Min Days: " << sol.minDays(bloomDay5, 2, 2) << endl; // Expected: -1
    cout << endl;

    return 0;
}

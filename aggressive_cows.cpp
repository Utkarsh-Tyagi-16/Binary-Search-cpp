#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to check if we can place 'cows' number of cows
    // with at least 'dist' distance between each pair of adjacent cows
    bool cowWePlace(vector<int> stalls, int dist, int cows)
    {
        int cntCows = 1, last = stalls[0]; // place first cow at stalls[0]
        for (int i = 1; i < stalls.size(); i++)
        {
            // if the gap between current stall and last placed cow >= dist,
            // place a cow here
            if (stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows >= cows) return true; // all cows placed successfully
        }
        return false;
    }

    // Binary search on the answer (minimum distance between cows)
    // to find the largest minimum distance possible
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end()); // sort stalls to apply binary search
        int low = 0;
        int high = stalls[n - 1]; // max possible distance
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (cowWePlace(stalls, mid, k) == true)
            {
                low = mid + 1; // try for a larger minimum distance
            }
            else
            {
                high = mid - 1; // reduce the minimum distance
            }
        }
        return high; // high holds the largest minimum distance
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "Stalls: {1, 2, 4, 8, 9}, Cows: " << k1 << endl;
    cout << "Largest minimum distance: " << sol.aggressiveCows(stalls1, k1) << endl;

    // Test case 2
    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << "\nStalls: {10, 1, 2, 7, 5}, Cows: " << k2 << endl;
    cout << "Largest minimum distance: " << sol.aggressiveCows(stalls2, k2) << endl;

    // Test case 3
    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << "\nStalls: {2, 12, 11, 3, 26, 7}, Cows: " << k3 << endl;
    cout << "Largest minimum distance: " << sol.aggressiveCows(stalls3, k3) << endl;

    return 0;
}

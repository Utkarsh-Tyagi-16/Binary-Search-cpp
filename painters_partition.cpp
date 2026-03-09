#include <bits/stdc++.h>
using namespace std;

// Returns the number of painters needed if each painter
// can paint at most 'maxTime' units worth of boards
int paintersRequired(vector<int>& boards, long long maxTime)
{
    int painters = 1;
    long long time = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        // If the current painter can handle this board
        if (time + boards[i] <= maxTime)
        {
            time += boards[i];
        }
        // Otherwise, assign a new painter
        else
        {
            painters++;
            time = boards[i];
        }
    }

    return painters;
}

// Binary search to find the minimum possible maximum time
// any single painter spends
int findLargestMinDistance(vector<int>& boards, int k)
{
    // Minimum = largest single board (a painter must paint at least 1 board)
    long long low = *max_element(boards.begin(), boards.end());
    // Maximum = sum of all boards (1 painter paints everything)
    long long high = accumulate(boards.begin(), boards.end(), 0LL);
    long long ans = high;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        // If k painters can handle it with maxTime = mid, try less time
        if (paintersRequired(boards, mid) <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        // Otherwise, we need more time per painter
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // Test Case 1
    vector<int> boards1 = {10, 20, 30, 40};
    int k1 = 2;
    cout << "Test 1: " << findLargestMinDistance(boards1, k1) << endl; // 60

    // Test Case 2
    vector<int> boards2 = {5, 5, 5, 5};
    int k2 = 2;
    cout << "Test 2: " << findLargestMinDistance(boards2, k2) << endl; // 10

    // Test Case 3
    vector<int> boards3 = {48, 90};
    int k3 = 2;
    cout << "Test 3: " << findLargestMinDistance(boards3, k3) << endl; // 90

    // Test Case 4: Single painter paints all
    vector<int> boards4 = {12, 34, 67, 90};
    int k4 = 1;
    cout << "Test 4: " << findLargestMinDistance(boards4, k4) << endl; // 203

    return 0;
}

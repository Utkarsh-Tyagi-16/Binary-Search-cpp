#include <bits/stdc++.h>
using namespace std;

// Function to count the number of students needed
// if each student can read at most 'pages' pages
int countStudents(vector<int>& arr, int pages)
{
    int students = 1;          // Start with 1 student
    long long pagesStudent = 0; // Pages assigned to the current student

    for (int i = 0; i < arr.size(); i++)
    {
        // If the current student can take this book
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        // Otherwise, assign it to the next student
        else
        {
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

// Binary search to find the minimum possible maximum pages
// allocated to any student
int findPages(vector<int>& arr, int n, int m)
{
    // If students are more than books, allocation is impossible
    if (m > n) return -1;

    // Minimum possible answer = max element (a student must read at least 1 full book)
    int low = *max_element(arr.begin(), arr.end());
    // Maximum possible answer = sum of all pages (1 student reads everything)
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int student = countStudents(arr, mid);

        // If more students are needed, increase the page limit
        if (student > m)
        {
            low = mid + 1;
        }
        // Otherwise, try to minimize the page limit
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    // Test Case 1
    vector<int> arr1 = {12, 34, 67, 90};
    int n1 = 4, m1 = 2;
    cout << "Test 1: " << findPages(arr1, n1, m1) << endl; // Output: 113

    // Test Case 2
    vector<int> arr2 = {25, 46, 28, 49, 24};
    int n2 = 5, m2 = 4;
    cout << "Test 2: " << findPages(arr2, n2, m2) << endl; // Output: 71

    // Test Case 3: More students than books
    vector<int> arr3 = {10, 20};
    int n3 = 2, m3 = 5;
    cout << "Test 3: " << findPages(arr3, n3, m3) << endl; // Output: -1

    // Test Case 4: Single student
    vector<int> arr4 = {15, 10, 19, 10, 5, 18, 7};
    int n4 = 7, m4 = 1;
    cout << "Test 4: " << findPages(arr4, n4, m4) << endl; // Output: 84

    return 0;
}

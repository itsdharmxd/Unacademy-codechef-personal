// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    void heapify(int arr[], int i, int n)
    {
        int L = (2 * i) + 1;
        int R = (2 * i) + 2;
        int largest = arr[i], index = i;
        if (L <= n && arr[L] < largest)
        {
            index = L;
            largest = arr[L];
        }
        if (R <= n && arr[R] < largest)
        {
            index = R;
            largest = arr[R];
        }
        if (i != index)
        {
            swap(arr[i], arr[index]);

            heapify(arr, index, n);
        }
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        int mid = (l + r) / 2;
        for (int i = mid; i >= l; i--)
        {

            heapify(arr, i, r);
        }
        int max = 0;
        for (int i = 0; i < k; i++)
        {

            max = arr[0];
            arr[0] = arr[r];
            heapify(arr, 0, r);
            r--;
        }
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends
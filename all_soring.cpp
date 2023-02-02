
#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define ll long long
#define rep(a, b, c) for (ll a = b; a < c; a++)
#define repr(a, b, c) for (ll a = b; a >= c; a--)
#define fst first
#define snd second
#define pb push_back
#define pii  pair<ll,ll>
#define vi   vector<ll>
#define all(c) ((c).begin()), ((c).end())
#define test()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define LOG2(X) ((unsigned)(8 * sizeof(unsigned long long) - __builtin_clzll((unsigned long long)(X)) - 1))


void selection(vector<int>&arr){
    int n = arr.size();
    for (int i = 0; i < n-1;i++){
        int mini = i;
        for (int j = i; j < n;j++){
            if(arr[j]<arr[i])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
    
}


void mergesort(vector<int>&arr,int l,int r ){
   if(l>=r)
       return;
   int mid = (l + r) /2;
   mergesort(arr, l, mid);
   mergesort(arr, mid + 1, r);
   vector<int> ans;
   int i = l, j = mid + 1;
   while((i<=mid)&&(j<=r)){
    if(arr[i]<=arr[j]){
        ans.push_back(arr[i]);
        i++;
    }else{
        ans.push_back(arr[j]);
        j++;
    }
   }
   while(i<=mid){
       ans.push_back(arr[i]);
       i++;
   }
   while (j <= r)
   {
       ans.push_back(arr[j]);
       j++;
   }
   for (int i = l; i <= r;i++){
       arr[i] = ans[i - l];
   }
}





void quicksort(vector<int> &arr,int l, int r){
 
   if(l>=r)
       return;

   int m = l;
   srand(time(NULL));
   int pivotindex = l + (rand() % (r - l+1));
   swap(arr[r], arr[pivotindex]);

   for (int i = l; i < r;i++){
       if(arr[i]<=arr[r]){
           swap(arr[i], arr[m]);
           m++;
       }
   }
   swap(arr[m], arr[r]);
   int pivot = m;

   quicksort(arr, l, pivot - 1);
   quicksort(arr, pivot + 1, r);
}



void insersion(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0;j--){
            if(arr[j-1]>arr[j])
                swap(arr[j - 1], arr[j]);
        }
    }
}

void bubble(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool f = true;
        for (int j =0 ; j < n-i-1; j++)
        {
           if(arr[j+1]<arr[j]){
               swap(arr[j+1], arr[j]);
               f = false;
               }
        }
        if(f)
            break;
    }
}

int solve()
{
    vector<int> arr = {10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5};

  //  selection(arr);
  //    bubble(arr);
    quicksort(arr, 0, arr.size() - 1);

    mergesort(arr, 0, arr.size() - 1);
    rep(i,0,arr.size()){
        cout << arr[i]<<" ";
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
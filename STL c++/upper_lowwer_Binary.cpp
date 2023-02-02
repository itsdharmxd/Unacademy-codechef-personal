
#include <bits/stdc++.h>
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

/*
  we can use binary search in non sorted array also

   partioned  array wear element is  in write position and   
   1. {4,3,2,1,5,9,8,7,6,}  <= we can search 5 here as all other number are on respective side 
   2. rotated aaray {5,6,7,8,9,1,2,3,4}

*/




int solve()
{
    vector<int>arr={0,2,3,4,5,6,7,8,9};
    //say if value is present or not
    cout<< binary_search(all(arr),5)<<endl;  // return bool;
     // value greater
    cout<<(upper_bound(all(arr),1)-arr.begin())<<endl;
   
     // value greater or equal
    cout<<(lower_bound(all(arr),1)-arr.begin())<<endl;
    
    
 


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
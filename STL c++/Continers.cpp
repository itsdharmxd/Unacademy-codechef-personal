
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
/**
 * 
 *  For sort() it is O(n*log(n))
 *  For stable_sort() it is O(n*log^2(n)) 
 */

void display(vector<int> &arr){
     rep(i,0,arr.size()){
        cout<<arr[i]<<" ";
     } 
}


int solve()
{
    
     vector<int> arr ={4,3,8,3};

     sort(all(arr));  // O(nlog(n))

     stable_sort(all(arr)); // O(nlog^2(n))
      
     *max_element(all(arr));
     *min_element(all(arr));
     accumulate(all(arr),0);
 
     /**
      * have a cshift function for shifting
      * but have limited functions
      *   cshift =circular shift
      *   shift  = non cirecular shift 
      */
      valarray<int>arr2={1,2,3,4,5,6,4,7,8};
      
     arr2= arr2.shift(3);
      rep(i,0,arr2.size())cout<<arr2[i]<<" ";

       
      
         
   




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
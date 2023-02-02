
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

// https://www.spoj.com/problems/SUBSUMS/



// bit masking
vector<ll> subsetsums(vector<ll>&arr){
     
     int n= arr.size();
     vector<ll>result;
    
     for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1) sum += arr[j];
        }
        result.push_back(sum);

     }
     

     return result;
}


int solve()
{

    ll n,a,b;    

    cin>>n>>a>>b;
    vector<ll>arr(n);
    rep(i,0,n)cin>>arr[i];

    vector<ll>left,right;

    rep(i,0,n){
        if(i<(n/2))left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    
    vector<ll>left_sum=subsetsums(left);
    vector<ll>right_sum=subsetsums(right);


    sort(all(right_sum));
    ll ans=0;
    for(auto x : left_sum){
        ans+=upper_bound(all(right_sum),b-x)-lower_bound(all(right_sum),a-x);
    }

      cout<<ans;

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
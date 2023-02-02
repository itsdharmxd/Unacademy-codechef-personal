
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



int solve()
{
    int n,m;
    cin>>n>>m;

    int m=sqrt(n)+1; // number of blocks
    
    vi arr(n), brr(m);

    rep(i,0,n){
        cin>>arr[i];
        brr[i/m]+=arr[i];
    }

    int q;
    cin>>q;
    while(q--){
        int l,r,ans=0;
        cin>>l>>r;

        for(int i=l;i<=r;){
            
            if(i%m==0 && i+m-1<=r){
                ans+=brr[i/m];
                i+=m;
            }else{
                ans+=arr[i];
                i++;
            }
        }
      cout<<ans<<endl;
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
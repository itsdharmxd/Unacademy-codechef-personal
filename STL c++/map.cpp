
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


ll  util(ll n){
   if(n==0)return 0;
   if(n==1) return 2;

   ll res=0;

   if(n%2==1){
     res+=n+1;
     res+=util(2*(util((n-1)/2)));
   }else{
       res+=util((util((n-1)/2)));
       res+=util((util((n-1)/2))+1);
       res+=n+1;
   
   }

  return res;
}




int solve()
{
 

   ll n,m;
   cin>>n>>m;

   ll ma=((n+1)*(n+2))/2;
   ma--;
  
  ll mi=util(n);

    if(m<mi){
        cout<<-1<<endl;
    }else if(m>ma){
        cout<<m-ma<<endl;
    }else{
        cout<<0<<endl;
    }


    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
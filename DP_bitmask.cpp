
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
const int N = 20;
int dp[1 << N][N];
int n;
int adj[N][N];
int cunt = 0;

/*
 look at DP_bitmask.cpp
*/
void bitmask(int mask,int node){
    //base case
    if (!(mask & (mask - 1)))
    {
        dp[mask][node] = adj[LOG2(mask)][node];     
        return;
    }
     // when state is already calculated
    if(dp[mask][node]!=-1){
        return ;
    }
    cunt++;
    int ans = 0;


    rep(i, 0, n)
    {   //self node 
        if (i == node)
            continue;

        //if already  calculated  
        if(ans){
            continue;
        }  

        // if bit is set then calculate  
        if ((mask >> i) & 1)
        {
            int newmask = mask & ~(1 << i);
                 
                bitmask(newmask, i);
            ans |= (dp[newmask][i] && adj[i][node]);
        }
       
   }
   
   dp[mask][node] = ans;
}

int solve()
{   // Number of nodes
    cin >> n;

    memset(dp, -1, sizeof(dp));

    // edge matrix
    rep(i, 0, n)
        rep(j, 0, n)
             cin>>adj[i][j];
    

    // mask where all bits are set   
    int fullmask=(1 << n) - 1;
  

   
  rep(i,0,n){
        bitmask(fullmask & ~(1 << i), i);
        dp[fullmask][i] = dp[fullmask & ~(1 << i)][i]&adj[i][i];
  }
  
  cout << cunt << endl;
  
  rep(i,0,n){
      if(dp[fullmask][i]){
          cout << "YES" << endl;
          return 0;
      }
  }

  cout << "NO" << endl;

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
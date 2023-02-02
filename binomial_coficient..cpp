
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
 *  n+1Cr= nCr+ nC(r-1)
*/


int binomialCofficient(int n,int k){
   vector<vector<int>> table(n+1,vector<int>(k+1,0));

   for(int i=0;i<=n;i++){
    for(int j=0;j<=min(i,k);j++){
        // base
        if(j==0 || j==i){
            table[i][j]=1;
        }else{

            table[i][j]=table[i-1][j-1]+table[i-1][j];
        }
    }
   }
  
  return table[n][k];

}

int solve()
{
    
 


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
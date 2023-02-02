
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
vector<int> g[10];
int tree = 0, back = 0, forwar = 0, cross=0;
vector<int> tim(10, 0), v(10, 0);
int timer = -1;
bool dfs_directed(int node ,int parent){
    tim[node] = ++timer;
    v[node] = 1;

    for(auto child:g[node]){
        if(child==parent)
            continue;
       if(v[child]==0){
           // tree edge
           tree++;
           if(dfs_directed(child,node)){
               return true;
           }
       }else if(v[child]==1){
           //back edge
           back++;
           //return true;
       }else if( tim[child]>tim[node] ){
           // fowrard edge
           forwar++;
       }else if(tim[child]<tim[node]){
           //cross edge
           cross++;
       }


    }

    v[node] = 2;

    return false;
}




int solve()
{
    int n;
    cin >> n;
    rep(i,0,n){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
    }
    dfs_directed(1, 0);
    dfs_directed(7, 0);

    cout << tree << " " << back << " " << forwar << " " << cross << endl;

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

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

const int N = 1e5;

vector<int> gr[N],grr[N];
int vis[N] , col[N];
vector<int>order;


// topological sort
void dfs1(int cur){
    vis[cur]=1;
    
    for(auto x : gr[cur]){
        if(!vis[x])dfs1(x);
    }
   order.pb(cur);
}

// dfs on reverse graph
void dfs2(int cur,int comp){
    vis[cur]=1;
    col[cur]= comp; 
    for(auto x : grr[cur]){
        if(!vis[x])dfs2(x,comp);
    }
}




int solve()
{
    int n,m;
    cin>>n>>m;
   
   for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    gr[x].pb(y);
    grr[y].pb(x);
   }

   for(int i=1;i<=n;i++){
     if(!vis[i]) dfs1(i);
   }
   reverse(all(order));
   memset(vis,0,sizeof(vis));

   int comp=1;
   for(int x: order){
     if(!vis[x]) dfs2(x,comp++);
   }

    for(int i=1;i<=n;i++){
        cout<<1<<" "<<col[i]<<'\n';
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
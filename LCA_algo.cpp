
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


// O(n)
const  int N=1e5;

vector<int>gr[N];
int dep[N],Par[N];


int LCA(int u,int v){
    if(v==u) return v;

    if(dep[u]<dep[v])swap(u,v);
  
    int diff=dep[u]-dep[v];

    while (diff--)
    {
        u=Par[u];
    }
    while (u!=v)
    {
        u=Par[u];
        v=Par[v];
    }
    
    return u;
    


}



void dfs(int node,int par){
  Par[node]=par;
  dep[node]=dep[par]+1;

   for(int x : gr[node]){
    if(x!=par){
        dfs(x,node);
    }
   }


}


int solve()
{
    int n;
    cin>>n;

    for(int i = 1; i<n;i++){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    
    dfs(1,0);


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
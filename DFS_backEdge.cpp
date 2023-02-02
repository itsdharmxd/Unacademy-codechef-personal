
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


const int N=1e5;

vector<int> gr[N];
int vis[N];
bool cycle=false;


void dfs(int node,int par){
   vis[node]=1;

   for(auto x : gr[node]){
    if(!vis[x]){
        dfs(x,node);
    }else if(x!=par) {
        // backedge
        cout<<node<<" "<<x<<endl;
        cycle=true;

    }
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
        gr[y].pb(x);
    }

    for(int i=1;i<=n;i++){
       if(!vis[i]){
        dfs(i,-1);
       }
    }
    
    if(cycle) cout<<"cycle";
    else cout<<"No cycle";


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
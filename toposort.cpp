
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


// 1
// 6 7   v   e
// 1 4   x -> y
// 1 3
// 6 3
// 6 1
// 5 3
// 5 2
// 4 2

const int N=6;
vector<int>g[N+1];



// topo sort with  DFS and  Stack


void util(int node,stack<int> &stk, vector<int>&visited ){
    if(visited[node])return; 
    
    visited[node]=true;

    for(int v : g[node]){
        util(v,stk,visited);
    }
stk.push(node);
}

void dfs_stack(){

  stack<int> stk;
  vector<int> visited(N+1,false);

  rep(i,1,N+1){
    if(visited[i]==false){
        util(i,stk,visited);
    }
  }

  while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
  }

}










////////////////////////////////////////////////////////////////////////////


//   Topo sort   (V+E)  Non- recursive Kahns algo
void topo(){

 vector<int>inedge(N+1,0);

  rep(i,1,N+1){
    for(int v : g[i]){ 
        inedge[v]++;
    }
  }
  queue<int> que;

  rep(i,1,N+1)if(inedge[i]==0){que.push(i);  // V
  cout<<i<<" ";
  inedge[i]=-1;
  }


  while (!que.empty())
  {
   while(!que.empty()){
    int  curr=que.front();
    que.pop();
    for(int k : g[curr]){     // E
        inedge[k]--;
       
    }
   }
    rep(i,1,N+1)if(inedge[i]==0){que.push(i); // V
    cout<<i<<" "; 
  inedge[i]=-1;
  }


  }
  

   

  


}



int solve()
{
    
 int  v,e;
 cin>>v>>e;

 while (e--)
 {
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
 }
 
 topo();
  cout<<"////////////////////////////////////"<<endl;
  dfs_stack();

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

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
 * By default MAX heap
 * 
 * greater<int> for min HEAP
 * 
 */

class Compare{
  public:
  bool operator()(int a,int b){

    return a>b; // min     greater<int>

    return a<b;   // max     lease
  }
  
};


int solve()
{
//   priority_queue<int,vector<int>,greater<int>> pq;
    // priority_queue<int,vector<int>,Compare> pq;        // important
  priority_queue<int,vector<int>,less<int>> pq;
 
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);    
  pq.push(5);
  
  
  cout<<pq.top();


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
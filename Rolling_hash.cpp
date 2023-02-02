
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

ll p = 31;
ll mod = 1e9 + 7;

ll hashh(string str){
    ll ans=0;
    for(char a:str){
        ans= (((ans * p)) + (a-'a'+1))%mod;
    }
    return ans;
}

vector<ll> rolling_hash(string text,string pat){

    ll n = text.length();
    ll k = pat.length();
    if(k>n){
        return vi{};
    }
    ll text_hash = hashh(text.substr(0, k));
    ll pat_hash = hashh(pat);
    vi ans;
    if(text_hash==pat_hash){
        ans.push_back(0);
    }
    ll pow_p = 1;
    rep(i, 0, k - 1)
    {
        pow_p =(pow_p* p)%mod;
   }

    ll curr_hash = text_hash;
    rep(i,1,n-(k-1)){
        ll first = text[i - 1] - 'a' + 1;
        ll last = text[i + (k - 1)]-'a'+1;

        curr_hash =(curr_hash- ((first * pow_p)%mod)+mod)%mod;
        curr_hash =(curr_hash* p)%mod;
        curr_hash =(curr_hash+ last)%mod;

      if(curr_hash==pat_hash){
          ans.push_back(i);
      }

    }


    return ans;
    }




int solve()
{
    vi arr=rolling_hash("dharmeshdharmeshhhhhh","dharmesh");

    for(auto a:arr){
        cout << a << " " << endl;
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
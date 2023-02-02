
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b, c) for (ll a = b; a < c; a++)
#define repr(a, b, c) for (ll a = b; a >= c; a--)
#define fst first
#define snd second
#define pb push_back
#define pii pair<ll, ll>
#define vi vector<ll>
#define all(c) ((c).begin()), ((c).end())
#define test()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define LOG2(X) ((unsigned)(8 * sizeof(unsigned long long) - __builtin_clzll((unsigned long long)(X)) - 1))

// Digit DP  // https : //codeforces.com/problemset/problem/1036/C

        string s;
ll dp[20][5][2];

ll recur(int pos, int count, int tight)
{
    if (dp[pos][count][tight] != -1)
        return dp[pos][count][tight];
    if (count > 3)
    {
        return 0;
    }

    if (pos == s.size())
    {
        return 1;
    }

    ll ans = 0;
    rep(i, 0, 10)
    {

        ans += recur(pos + 1, count + (i > 0), tight && (i == (s[pos] - '0')));

        if (tight && (i == (s[pos] - '0')))
        {
            break;
        }
    }

    return dp[pos][count][tight] = ans;
}

int solve()
{
    memset(dp, -1, sizeof(dp));
    ll l;
    cin >> l;
    l--;
    s = to_string(l);

    ll left = recur(0, 0, 1);
    memset(dp, -1, sizeof(dp));

    cin >> s;

    ll right = recur(0, 0, 1);

    cout << (right - left) << endl;

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
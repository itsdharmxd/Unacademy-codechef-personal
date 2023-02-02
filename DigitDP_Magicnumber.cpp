// Got AC

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define range(a, b) substr(a, b - a + 1)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// link =https://codeforces.com/contest/628/problem/D
int dp[2005][2][2005][2][2];
int m, d; // invariant for a test case
string s;
int solve(int pos, bool tight, int mo, bool st, bool even)
{
    int n = s.size();
    // Bc
    if (pos == n) // DigDP base-case{
    {
        return (mo == 0);
    }

    // Lu
    if (dp[pos][tight][mo][st][even] != -1)
        return dp[pos][tight][mo][st][even];

    // Big
    int ub = (tight ? (s[pos] - '0') : 9);
    int ans = 0;
    // Cases: whether started or not
    if (st == 0)
    {
        // Logic when not yet statred
        // Here even is False
        // 2 poss --> either start from here or dont
        ans = (ans + solve(pos + 1, tight & (s[pos] == '0'), mo, st, 0)) % mod; // case 2 i.e put 0
        for (int digit = 1; digit <= ub; digit++)
        {
            int mo_prop = (10 * mo + digit) % m; // left shift -> mo_prop
            bool tight_prop = (tight & (digit == ub));
            if (digit != d)
                ans = (ans + solve(pos + 1, tight_prop, mo_prop, 1, 1)) % mod;
        }
    }

    // st != 0 --> Not yet statrted
    else
    {
        // Logic when already statred
        // This alredy statred somewhere b4
        for (int digit = 0; digit <= ub; digit++)
        {
            if (even and (digit == d))
            {
                int mo_prop = ((10 * mo) + digit) % m; // left shift -> mo_prop
                bool tight_prop = (tight & (digit == ub));
                ans = (ans + solve(pos + 1, tight_prop, mo_prop, st, !even)) % mod;
            }
            else if ((!even) and (digit != d))
            {
                int mo_prop = ((10 * mo) + digit) % m; // left shift -> mo_prop
                bool tight_prop = (tight & (digit == ub));
                ans = (ans + solve(pos + 1, tight_prop, mo_prop, st, !even)) % mod;
            }
        }
    }

    return dp[pos][tight][mo][st][even] = ans;
}

int32_t main()
{
    file_i_o();

    // set global vars
    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    s = a; // set global vars
    memset(dp, -1, sizeof dp);
    int ans1 = solve(0, 1, 0, 0, 0);
    // trace(ans1);

    s = b;
    memset(dp, -1, sizeof dp);
    int ans2 = solve(0, 1, 0, 0, 0);
    // trace(ans2);

    int ans = (ans2 - ans1 + mod) % mod;
    // cout << ans << "\n";
    // pre[R] - pre[L] + ( L == magic_num )
    // Brute force
    int n = a.size(), mo = 0; // a is L
    bool f = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        int pos = i + 1;
        if ((pos % 2 == 1) and ((a[i] - '0') == d))
        {
            f = 0;
        }
        else if ((pos % 2 == 0) and ((a[i] - '0') != d))
        {
            f = 0;
        }
        mo = ((10 * mo) + (a[i] - '0')) % m;
    }

    if (mo == 0 and f == 1)
        ans = (ans + 1) % mod;
    cout << ans << "\n";

    return 0;
}
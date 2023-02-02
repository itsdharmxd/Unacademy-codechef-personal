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
// https : //www.spoj.com/problems/GIVEAWAY/
vector<int> arr;

int solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    int blockz = sqrt(n);
    int noofblock = (n + blockz - 1) / blockz;
    vector<int> block[noofblock];
    rep(i, 0, n)
    {
        cin >> arr[i];
        block[i / blockz].pb(arr[i]);
    }
    for (int i = 0; i < noofblock; i++)
    {
        sort(all(block[i]));
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, value;

            cin >> index >> value;
            index--;
            int indexblock = index / blockz;
            int oldvalue = arr[index];
            int lo = 0, high = block[indexblock].size() - 1, mid;

            while (lo <= high)
            {
                mid = (lo + high) >> 1;
                if (oldvalue < block[indexblock][mid])
                {
                    high = mid - 1;
                }
                else if (oldvalue > block[indexblock][mid])
                {
                    lo = mid + 1;
                }
                else
                {
                    block[indexblock][mid] = value;
                    break;
                }
            }
            arr[index] = value;
            while ((mid + 1 < block[indexblock].size()) && block[indexblock][mid] > block[indexblock][mid + 1])
            {
                swap(block[indexblock][mid], block[indexblock][mid + 1]);
                mid++;
            }
            while ((mid - 1 >= 0) && block[indexblock][mid] < block[indexblock][mid - 1])
            {
                swap(block[indexblock][mid], block[indexblock][mid - 1]);
                mid--;
            }
        }
        else
        {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;

            int lblock = l / blockz, rblock = r / blockz;
            int lend = lblock * blockz + blockz - 1, rstart = rblock * blockz;
            int ans = 0;
            // left block
            for (int i = l; i <= min(r, lend); i++)
            {
                if (arr[i] >= c)
                {
                    ans++;
                }
            }
            if (lblock != rblock)
            {
                // right block
                for (int i = max(rstart, l); i <= r; i++)
                {
                    if (arr[i] >= c)
                    {
                        ans++;
                    }
                }
                // blocks
                for (int i = lblock + 1; i < rblock; i++)
                {
                    ans += block[i].end() - lower_bound(all(block[i]), c);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    //	cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
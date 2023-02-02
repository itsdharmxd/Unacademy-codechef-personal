
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

class info
{
public:
    int sum;
    info()
    {
    }
    info(int val)
    {
        sum = val;
    }
};

class segTree
{ // 1-based
    vector<info> tree;
    int n;
    vi arr;

    info merge(info &left, info &right)
    {

        return info(left.sum + right.sum);
    }

    void build(int cur, int l, int r)
    {

        // TC = O(2N)
        if (l == r)
        {
            tree[cur] = info(arr[l]);
            return;
        }
        int mid = l + r >> 1;
        build(2 * cur, l, mid);
        build(2 * cur + 1, mid + 1, r);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }

    info query(int cur, int tl, int tr, int ql, int qr)
    {
        // no overlap
        if (qr < tl || ql > tr)
        {
            return info(0);
        }
        // complete overlap
        if (tl >= ql && tr <= qr)
        {
            return tree[cur];
        }

        // partial overlap
        int mid = tl + tr >> 1;
        info left = query(2 * cur, tl, mid, ql, qr);
        info right = query(2 * cur + 1, mid + 1, tr, ql, qr);
        return merge(left, right);
    }
    void update(int cur, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[cur] = info(val);
            return;
        }

        int mid = l + r >> 1;
        if (pos <= mid)
        {
            update(2 * cur, l, mid, pos, val);
        }
        else
        {
            update(2 * cur + 1, mid + 1, r, pos, val);
        }
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }

    void updateRange(int cur, int tl, int tr, int ul, int ur, int val)
    {

        int to_add = intersection_len(tl, tr, ul, ur) * val;
        tree[cur].sum += to_add;
        if (to_add == 0 || tl == tr)
            return;

        int mid = tl + tr >> 1;
        updateRange(2 * cur, tl, mid, ul, ur, val);
        updateRange(2 * cur + 1, mid + 1, tr, ul, ur, val);
    }

public:
    segTree(vi a)
    { //  arr is 0-based
        n = a.size();
        tree.resize(4 * n + 1);
        arr = a;
        build(1, 0, n - 1); // 0(n)
    }
    info query(int l, int r)
    { // O(logn)
        return query(1, 0, n - 1, l, r);
    }
    void update(int pos, int val)
    { // O(log n)
        update(1, 0, n - 1, pos, val);
    }
    void updateRange(int l, int r, int val)
    {
        updateRange(1, 1, n, l, r, val);
    }
};
int intersection_len(int l1, int r1, int l2, int r2)
{
    return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int solve()
{
    vi arr = {1, 2, 3, 4, 5, 6};
    segTree st(arr);
    st.update(3, 100);
    cout << st.query(0, arr.size() - 1).sum;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
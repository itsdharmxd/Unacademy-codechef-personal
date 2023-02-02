
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
    ll sum;
    info()
    {
    }
    info(ll val)
    {
        sum = val;
    }
};

class info2
{
public:
    ll add;
    info2()
    {
        add = 0;
    }
    void update(ll val)
    {
        add += val;
    }
    void reset()
    {
        add = 0;
    }
    info apply(info val, ll l, ll r)
    {
        return info(val.sum + (r - l + 1) * add);
    }
};

class segTree
{ // 1-based
    vector<info> tree;
    vector<info2> lazy;
    ll n;
    vi arr;

    info merge(info &left, info &right)
    {

        return info(left.sum + right.sum);
    }

    void build(ll cur, ll l, ll r)
    {

        // TC = O(2N)
        if (l == r)
        {
            tree[cur] = info(arr[l]);
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * cur, l, mid);
        build(2 * cur + 1, mid + 1, r);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }

    info query(ll cur, ll tl, ll tr, ll ql, ll qr)
    {
        // Apply existing updates
        if (lazy[cur].add)
        {
            // tree[cur].sum += (tr - tl + 1) * lazy[cur].add;
            tree[cur] = lazy[cur].apply(tree[cur], tl, tr);
            if (tl != tr)
            {
                lazy[2 * cur].update(lazy[cur].add);
                lazy[2 * cur + 1].update(lazy[cur].add);
            }
            lazy[cur].reset();
        }

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
        ll mid = (tl + tr) >> 1;
        info left = query(2 * cur, tl, mid, ql, qr);
        info right = query(2 * cur + 1, mid + 1, tr, ql, qr);
        return merge(left, right);
    }
    void apply_ans_pass(ll cur, ll tl, ll tr)
    {
        // Apply existing updates
        if (lazy[cur].add)
        {
            // tree[cur].sum += (tr - tl + 1) * lazy[cur].add;
            tree[cur] = lazy[cur].apply(tree[cur], tl, tr);
            if (tl != tr)
            {
                lazy[2 * cur].update(lazy[cur].add);
                lazy[2 * cur + 1].update(lazy[cur].add);
            }
            lazy[cur].reset();
        }
    }

    void update(ll cur, ll tl, ll tr, ll ul, ll ur, ll val)
    {
        // apply updates
        apply_ans_pass(cur, tl, tr);

        // No overlap
        if (ur < tl || ul > tr)
        {
            return;
        }
        // comple overlap
        if (tl >= ul && tr <= ur)
        {
            lazy[cur].update(val);
            apply_ans_pass(cur, tl, tr);
            return;
        }

        ll mid = (tl + tr) >> 1;
        update(2 * cur, tl, mid, ul, ur, val);
        update(2 * cur + 1, mid + 1, tr, ul, ur, val);
        tree[cur] = merge(tree[2 * cur], tree[2 * cur + 1]);
    }

    void updateRange(ll cur, ll tl, ll tr, ll ul, ll ur, ll val)
    {

        ll to_add = llersection_len(tl, tr, ul, ur) * val;
        tree[cur].sum += to_add;
        if (to_add == 0 || tl == tr)
            return;

        ll mid = (tl + tr) >> 1;
        updateRange(2 * cur, tl, mid, ul, ur, val);
        updateRange(2 * cur + 1, mid + 1, tr, ul, ur, val);
    }

public:
    segTree(vi a)
    { //  arr is 0-based
        n = a.size();
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        arr = a;
        build(1, 0, n - 1); // 0(n)
    }
    info query(ll l, ll r)
    { // O(logn)
        return query(1, 0, n - 1, l, r);
    }
    void update(ll l, ll r, ll val)
    { // O(log n)
        update(1, 0, n - 1, l, r, val);
    }
    void updateRange(ll l, ll r, ll val)
    {
        updateRange(1, 1, n, l, r, val);
    }
    ll llersection_len(ll l1, ll r1, ll l2, ll r2)
    {
        return max(0ll, min(r1, r2) - max(l1, l2) + 1);
    }
};

ll solve()
{
    ll n, q;
    cin >> n >> q;

    vi arr(n + 1);

    rep(i, 1, n + 1) cin >> arr[i];

    segTree st(arr);

    while (q--)
    {
        ll tp, a, b;
        cin >> tp;
        if (tp == 1)
        {
            cin >> a >> b;
            ll val;
            cin >> val;
            st.update(a, b, val);
        }
        else
        {
            ll id;
            cin >> id;
            cout << st.query(id, id).sum << endl;
        }
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
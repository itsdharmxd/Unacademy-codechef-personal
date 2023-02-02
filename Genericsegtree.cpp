
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

const int INF = 1e9;
const int mod = 1e9 + 7;
// associaltive opeation
struct my_node
{                 // value on main treee node
    ll value = 0; // 1

    my_node() {}
    my_node(ll val)
    {                /// for leaf node direct initialize
        value = val; // 2
    }
    void merge(const my_node &l, const my_node &r)
    {
        // left , right subtree to current node
        value = l.value + r.value; // 3
    }
};

struct my_update
{
    ll v = 0; // 4
    my_update() {}
    my_update(ll val)
    {
        v = val; // 5
    }
    void combine(my_update &other, const int32_t &tl, const int32_t &tr)
    {
        // New Update for range (other==new)
        v += other.v; // 6
    }
    // store the correct information in the my_node x
    void apply(my_node &x, const int32_t &tl, const int32_t &tr)
    { // apply update to the node tree

        x.value += (tr - tl + 1) * v; // 7
    }
};

template <typename node, typename update>
struct segtree
{
private:
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;

public:
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }

private:
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
        {
            return identity_element;
        }
        if (tl >= l && tr <= r)
        {
            return t[v];
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
        {
            return;
        }
        if (tl >= l && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};
// segtree<my_node, my_update> st(n);
// st.build(a);
// st.rupd(l, r, v);
// st.query(l, r).value

int solve()
{
    vi arr{1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = arr.size();
    segtree<my_node, my_update> st(n);
    st.build(arr);
    st.rupd(0, 4, 1);
    st.rupd(0, 4, 1);
    st.rupd(0, 4, 1);
    st.rupd(0, 4, 1);
    st.rupd(0, 4, 1);

    cout << st.query(0, 4).value;

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
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int p = 31;

int f(string s)
{
	int ans = 0;

	for (char ch : s)
	{
		int d = ch - 'a' + 1;
		ans = (ans * p + d) % mod;
	}

	return ans;
}

vector<int> match(string text, string pat)
{
	int n = text.length(), k = pat.length();

	if (n < k)
		return vi{};

	int pat_hash = f(pat);
	int text_hash = f(text.substr(0, k));

	vi ans;

	if (pat_hash == text_hash) // match at 0
		ans.pb(0);

	int pow_p = 1;
	for (int i = 0; i < k - 1; ++i)
		pow_p = (pow_p * p) % mod;

	for (int i = 1; i + k - 1 < n; ++i)
	{
		int rem_d = text[i - 1] - 'a' + 1;
		int add_d = text[i + k - 1] - 'a' + 1;

		text_hash = (text_hash - (rem_d * pow_p) % mod + mod) % mod;
		text_hash = (text_hash * p + add_d) % mod;

		if (text_hash == pat_hash)
			ans.pb(i);
	}

	return ans;
}

int32_t main()
{
	FIO;
    // freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	string pat = "dharmesh";
	string text = "dharmeshdharmesh";

	vi ans = match(text, pat);

	for (int i : ans)
		cout << i << ' ';
	return 0;
}
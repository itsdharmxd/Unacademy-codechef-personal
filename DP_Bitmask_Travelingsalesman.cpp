
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> adj, dp;

    int inf = 1e9;

    int n;

    void bitmask(int mask, int node)
    {

        if (mask == 1)
        {
            dp[mask][node] = adj[0][node];
            return;
        }
        if (!(mask & (mask - 1)))
        {
            dp[mask][node] = inf;
            return;
        }
        if (dp[mask][node] != inf)
            return;
        for (int i = 0; i < n; i++)
        {
            if (i == node)
                continue;
            if ((mask >> i) & 1)
            {
                int newmask = mask & ~(1 << i);
                bitmask(newmask, i);
                if (dp[newmask][i] != inf)
                    dp[mask][node] = min(dp[mask][node], dp[newmask][i] + adj[i][node]);
            }
        }
    }

    int total_cost(vector<vector<int>> cost)
    {

        dp.assign(1 << 10, vector<int>(10, inf));

        n = cost.size();
        adj = cost;
        for (int i = 0; i < n; i++)
        {
            dp[1 << i][i] = 0;
        }

        int fullmask = (1 << n) - 1;

        for (int i = 1; i < n; i++)
        {
            bitmask(fullmask & ~(1 << i), i);
            if (dp[fullmask & ~(1 << i)][i] != inf)
                dp[fullmask][0] = min(dp[fullmask][0], dp[fullmask & ~(1 << i)][i] + adj[i][0]);
        }

        return dp[fullmask][0];

        // Code here
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
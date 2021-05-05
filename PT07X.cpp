/*
 Writer : Harsh Agarwala
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//return  break continue
const ll inf = 1e18;
const ll N = 1e5 + 7;
ll ans = inf;
vector<ll>adj[N];
ll dp[N][2];
void dfs(int src, int par)
{
	dp[src][1] = 1;
	dp[src][0] = 0;
	for (auto it : adj[src])
	{
		if (it == par)continue;
		dfs(it, src);
		dp[src][1] += min(dp[it][0], dp[it][1]);
		dp[src][0] += dp[it][1];
	}
}
void solve()
{
	ll n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 1)
	{
		cout << 0; return;
	}
	dfs(1, 0);
	cout << min(dp[1][1], dp[1][0]);

}
int main()
{
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
/*
  Writer: Harsh Agarwala
*/
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define db1(x)                cout<<#x<<": "<<x<<"\n"
#define db2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n"
#define db3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n"
#define db4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a
#define setbits(x)      __builtin_popcountll(x)
#define str string
#define bhaag_basanti ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define eb emplace_back
#define pq priority_queue
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define sp(x,y)         fixed<<setprecision(y)<<x
#define nl '\n'
#define sz(x) ((int)(x).size())

typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef map<pll, int> mpll;
typedef vector<pll> vpll;
typedef vector<vector<ll> > vv;

const ll N = 2e5 + 1;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 1 ;

//return continue break
ll par[N];
ll find(int v)
{
	if (par[v] == v)return v;
	return par[v] = find(par[v]);
}
void solve()
{
	ll ans = 0, n, m;
	cin >> n >> m;
	ll a[n + 1];
	fo(i, 1, n + 1)cin >> a[i], par[i] = i;
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>>pq;
	fo(i, 0, m)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		pq.push({z, x, y});
	}
	while (!pq.empty())
	{
		ll k1 = get<0>(pq.top());
		ll k2 = get<1>(pq.top());
		ll k3 = get<2>(pq.top());
		pq.pop();
		k2 = find(k2);
		k3 = find(k3);
		if (a[k2] and a[k3] or (k2 == k3))continue;
		ans += k1;
		par[k3] = k2;
		if (a[k2] or a[k3])a[k2] = a[k3] = 1;
	}
	fo(i, 1, n + 1)
	{
		ll k1 = find(i);
		if (!a[k1])
		{
			cout << "impossible\n"; return;
		}
	}
	cout << ans << nl;
}
int main()
{
	bhaag_basanti

	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();

	}
}

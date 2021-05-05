/*
   Writer: Harsh Agarwala
*/
#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
#define db1(x)                cout<<#x<<": "<<x<<"\n"
#define db2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n"
#define db3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n"
#define db4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n"
////////////////////////////////////////////////////////////////////////////////////////
#define ll long long
#define ld long double
#define setbits(x)      __builtin_popcountll(x)
///////////////////////////////////////////////////////////////////////////////////////
#define bhaag_basanti ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///////////////////////////////////////////////////////////////////////////////////////
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sp(x,y)         fixed<<setprecision(y)<<x
///////////////////////////////////////////////////////////////////////////////////////
const ll N = 2e6 + 7;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 1 ;
///////////////////////////////////////////////////////////////////////////////////////


//return continue break
struct data {
	int sum, pref, suff, ans;
};

struct data t[4 * 50001];
struct data combine( struct data l, struct data r) {
	struct data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}
struct data make_data(int val) {
	struct data res;
	res.sum = val;
	res.pref = res.suff = res.ans = max(-15009, val);
	return res;
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = make_data(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = make_data(new_val);
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}
struct data query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_data(-15009);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine(query(v * 2, tl, tm, l, min(r, tm)),
	               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void solve()
{
	ll n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	build(a, 1, 0, n - 1);
	ll q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		struct data ANS = query(1, 0, n - 1, x - 1, y - 1);
		cout << ANS.ans << '\n';
	}
}

int main()
{
	bhaag_basanti

	ll tt = 1;
	// cin >> tt;
	while (tt--)
	{
		solve();

	}
}
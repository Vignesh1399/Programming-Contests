#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define cin in
#define cout out
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
using namespace std;

string to_string(int num, int dig) {
	string s = "";
	for (int i = 0; i < dig; i++) {
		s += ((num % 10) + '0');
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

ofstream out;
ifstream in;

const int max_test_files = 5;

//test_specific contents

// ll bsrch(ll l, ll r, ll n) {
// 	if (l == r)
// 		return l;
// 	ll mid = (l + r + 1) / 2;
// 	if ((mid * (mid + 1)) <= (2 * n))
// 		return bsrch(mid, r, n);
// 	else
// 		return bsrch(l, mid - 1, n);
// }

const int maxn = 1e5;
vector<int> adjlist[maxn + 1];
int vis[maxn + 1], n;
ll dp[maxn + 1][2], val[maxn + 1];

ll tik = 0;

void dfs(vector<ll> g[], ll s, vector<ll> &tin, vector<ll> &tout){
	tin[s] = tik++;
	for(auto i:g[s]){
		if(tin[i] == -1)
		dfs(g,i,tin,tout);
	}
	tout[s] = tik++;
}

bool ancestor(ll a, ll b,vector<ll> &tin, vector<ll> &tout){
	// check whether a is ancestor of b
	return tin[a]<=tin[b] && tout[a]>=tout[b];
}


void dfs(int cur) {
	vis[cur] = 1;
	for (auto u : adjlist[cur]) {
		if (vis[u])
			continue;
		dfs(u);
		dp[cur][1] += dp[u][0];
		dp[cur][0] += max(dp[u][0], dp[u][1]);
	}
}

void bfs(vector<ll> g[], queue<ll> &q, vector<ll> &d){
	while(!q.empty()){
		ll from = q.front();
		q.pop();
		for(auto to : g[from]){
			if(d[to] > -1) continue;
			d[to] = d[from] + 1;
			q.push(to);
		}
	}
}

void solve() {
  /*
	in >> n;
	for (int i = 1; i <= n; i++) {

		in >> val[i];
		dp[i][1] = val[i];
		dp[i][0] = 0;
		adjlist[i].clear();
		vis[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		in >> u >> v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	dfs(1);
	out << max(dp[1][0], dp[1][1]);
  */
    ll n,m,a,b,h;
	cin >> n >> m;
	vector<ll> g[n+1];
	vector<ll> d(n+1,-1);
	for(ll i=0;i<m;i++){
		cin  >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	cin >> h;
	queue<ll> q;
	for(ll i=0;i<h;i++){
		cin >> a;
		d[a] = 0;
		q.push(a);
	}
	bfs(g,q,d);
	for(ll i=1;i<=n;i++)
	cout<<d[i]<<" ";

}
//end of test_specific contents

int32_t main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name_ip = "input/input" + to_string(i, 2) + ".txt";
		string file_name_op = "output/output_rcv" + to_string(i, 2) + ".txt";
		in.open(file_name_ip.c_str(), std::ifstream::in);
		out.open(file_name_op.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		assert(in.is_open());
		solve();
		out.close();
		in.close();
		assert(!in.is_open());
		assert(!out.is_open());
	}
	return 0;
}
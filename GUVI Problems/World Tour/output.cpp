#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define cout out
#define cin in
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
#define sz(a) signed(a.size())
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
/*
const int maxn = 1e5;
vector<int> adjlist[maxn + 1];
int vis[maxn + 1], n;
ll dp[maxn + 1][2], val[maxn + 1];


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
*/

ll explore(ll i, ll j, vector<vector<ll>> &dp, vector<vector<ll>> &path,vector<pair<ll,ll>> g[]){
	if(i==1){
		if(j == 1)
		return 0;
		else
		return 1e9+1;
	}
	if(j<1)
	return 1e9+1;
	if(dp[i][j] != -1)
	return dp[i][j];
	ll ans = 1e9+1;
	for(auto x : g[i]){
		dp[x.first][j-1] = explore(x.first,j-1,dp,path,g);
		if(dp[x.first][j-1] + x.second <= ans){
			ans = dp[x.first][j-1] + x.second;
			path[i][j] = x.first;
		}
	}
	dp[i][j] = ans;
	return ans;
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
  	ll n,m,t;
	cin >> n >> m >> t;
	vector<pair<ll,ll>> g[n+1];
	for(ll i = 1;i<=m;i++){
		ll u,v,time;
		cin >> u >> v >> time;
		g[v].pb({u,time});
	}
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1)),path(n+1,vector<ll>(n+1,0));
	ll max_len = 0;
	for(ll i=1;i<=n;i++){
		if(explore(n,i,dp,path,g) <= t)
		max_len = i;
		//cout << n << " " << i << " " << dp[n][i] << "\n";
	}
	vector<ll> ans;
	ll cur = n;
	cout << max_len << "\n";
	while(max_len){
		ans.pb(cur);
		cur = path[cur][max_len];
		max_len--;
	}
	reverse(ans.begin(),ans.end());
	//for(auto i : ans)
	//cout << i << " ";
  	
}
//end of test_specific contents

int32_t main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name_ip = "input" + to_string(i, 2) + ".txt";
		string file_name_op = "output" + to_string(i, 2) + ".txt";
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
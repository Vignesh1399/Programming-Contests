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
string s[100001];
vector<ll> cost(1e6+1,0);
vector<vector<ll>> dp(1e6+1,vector<ll>(2,-1));
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
void z1bfs(ll i,ll j, vector<vector<int>> &ar, vector<vector<ll>> &d,ll n, ll m){
	d[i][j] = 0;
	deque <pair<ll,ll>> q;
	q.push_back({i,j});
	while(!q.empty()){
		pair<ll,ll> to = q.front();
		ll r = to.first;
		ll c = to.second;
		q.pop_front();
		if(r+1<=n){
			if(d[r+1][c] > d[r][c] + (ar[r][c] != ar[r+1][c])){
				d[r+1][c] = d[r][c] + (ar[r][c] != ar[r+1][c]);
				if(ar[r][c] != ar[r+1][c])
				q.push_back({r+1,c});
				else
				q.push_front({r+1,c});
			}
		}
		if(r-1>=1){
			if(d[r-1][c] > d[r][c] + (ar[r][c] != ar[r-1][c])){
				d[r-1][c] = d[r][c] + (ar[r][c] != ar[r-1][c]);
				if(ar[r][c] != ar[r-1][c])
				q.push_back({r-1,c});
				else
				q.push_front({r-1,c});
			}
		}
		if(c+1<=m){
			if(d[r][c+1] > d[r][c] + (ar[r][c] != ar[r][c+1])){
				d[r][c+1] = d[r][c] + (ar[r][c] != ar[r][c+1]);
				if(ar[r][c] != ar[r][c+1])
				q.push_back({r,c+1});
				else
				q.push_front({r,c+1});
			}
		}
		if(c-1>=1){
			if(d[r][c-1] > d[r][c] + (ar[r][c] != ar[r][c-1])){
				d[r][c-1] = d[r][c] + (ar[r][c] != ar[r][c-1]);
				if(ar[r][c] != ar[r][c-1])
				q.push_back({r,c-1});
				else
				q.push_front({r,c-1});
			}
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
  	ll n,m;
	cin >> n >> m; 
	vector<vector<ll>> d(n+1,vector<ll>(m+1,1e9));
	vector<vector<int>> ar(n+1,vector<int>(m+1,10));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
		}
	}
	z1bfs(1ll,1ll,ar,d,n,m);
	cout << d[n][m] << "\n";
  	
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
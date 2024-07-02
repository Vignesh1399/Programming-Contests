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
struct trip{
	ll l,r,c;
};

bool comp(struct trip a, struct trip b){
	if(a.l != b.l)
	return a.l < b.l;
	return a.c < b.c;
}

vector<struct trip> dur[200001];
vector<ll> sufc[200001];

ll bin_search(vector<struct trip> &ar, ll start){
	ll lb = 0,ub = sz(ar)-1;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		if(ar[mid].l <= start)
		lb = mid + 1;
		else 
		ub = mid - 1;
	}
	return lb;
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
  	ll n,x;
	cin >> n >> x;
	for(ll i=1;i<=n;i++){
		ll left,right,cost;
		cin >> left >> right >> cost;
		dur[right - left +1].pb({left,right,cost}); 
	}
	for(ll i=1;i<=2e5;i++)
	sort(dur[i].begin(),dur[i].end(),comp);
	for(ll i=1;i<=2e5;i++){
		if(!sz(dur[i])) continue;
		sufc[i].pb(dur[i].back().c);
		for(ll j=sz(dur[i])-2;j>=0;j--){
			ll x = sufc[i].back();
			sufc[i].pb(min(x,dur[i][j].c));
		}
		reverse(sufc[i].begin(),sufc[i].end());
	}
	ll ans = 1e10;
	for(ll i=1;i<=x;i++){
		for(ll j=0;j<sz(dur[i]);j++){
			ll temp = dur[i][j].c;
			ll idx = bin_search(dur[x-i],dur[i][j].r);
			//cout <<x-i << " " << idx << "\n";
			if(idx == sz(dur[x-i])) continue;
			temp += sufc[x-i][idx];
			ans = min(ans,temp);
		}
		//cout << ans << " \n";
	}
	if(ans == 1e10)
	cout << -1;
	else
	cout << ans;
  	
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
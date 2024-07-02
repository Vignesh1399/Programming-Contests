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

struct data{
	ll mn;
	data() : mn(0) {};
};

struct SegTree{
	ll N;
	vector<struct data> st;
	vector<ll> ar;
	
	void init(ll n){
		// To initialize
		N = n;
		st.resize(4*N+1);
		ar.resize(n+1);
	}
	void merge(struct data &cur, struct data &l, struct data &r){
		// Use any merging property
		cur.mn = max(l.mn , r.mn);
	}
	
	void build(ll node, ll s, ll e){
		if(s == e){
			st[node].mn = ar[s];
			return ;
		}
		ll mid = (s+e)/2;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		merge(st[node], st[2*node], st[2*node+1]);
	}
	struct data query(ll node, ll s, ll e, ll L, ll R){
		if(s>R || e<L){
			struct data d;
			return d;
		}
		else if(s>=L && e<=R)
			return st[node];
		ll mid = (s+e)/2;
		struct data p1 = query(2*node,s,mid,L,R);
		struct data p2 = query(2*node+1,mid+1,e,L,R);
		struct data ans;
		merge(ans,p1,p2);
		return ans;
	}
	void update(ll node, ll s, ll e, ll idx, ll val){
		if(s == e){
			st[node].mn += val;
			ar[s] += val;
			return ;
		}
		ll mid = (s+e)/2;
		if(idx<=mid)
		update(2*node,s,mid,idx,val);
		else
		update(2*node+1,mid+1,e,idx,val);
		merge(st[node],st[2*node],st[2*node+1]);
	}
};
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
  	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<ll>> ar(n+1,vector<ll>(m+1,-1));
	for(ll i=1;i<=n;i++){
		for(ll j =1;j<=m;j++)
			cin >> ar[i][j];
	}	
	// Initialise Segment Tree
	SegTree s[6];
	for(ll j=1;j<=m;j++){
		s[j].init(n);
		for(ll i=1;i<=n;i++){
			s[j].ar[i] = ar[i][j];
		}
		s[j].build(1,1,n);
	}
	ll l = 1, r = 1;
	ll ans_sz = 0;
	vector<ll> ans;
	while(r<=n){
		vector<ll> cur_shots;
		ll total_shots = 0;
		for(ll j=1;j<=m;j++){
			struct data Q = s[j].query(1,1,n,l,r);
			cur_shots.pb(Q.mn);
			total_shots += Q.mn;
		}
		if(total_shots <= k){
			if(r-l+1>ans_sz){
				ans = cur_shots;
				ans_sz = r-l+1;
			}
			r++;
		}
		else
		++l;
		if(l>r)
		r = l;
	}
	if(!sz(ans)){
		for(ll i=1;i<=m;i++)
		cout << 0 << " ";
	}
	for(auto i : ans)
	cout << i << " ";
  	
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
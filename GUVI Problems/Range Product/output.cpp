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
	data() : mn(-2) {} ;
};

struct SegTree{
	vector<data> tree;
	vector<data> ar;
	ll N;
	
	void init(ll n){
		N = 4*n + 1;
		tree.resize(N);
		ar.resize(n+1);
	}
	
	void merge(struct data &cur, struct data &l, struct data &r){
		cur.mn = l.mn * r.mn;
	}
	
	void build(ll node, ll s, ll e){
		if( s == e )
		tree[node] = ar[s];
		else{
			ll mid = (s+e)/2;
			build(2*node, s, mid);
			build(2*node+1, mid+1, e);
			merge(tree[node],tree[2*node], tree[2*node+1]);
		}
	}
	
	void update(ll node, ll s, ll e, ll idx, struct data &val){
		if( s == e ){
			tree[node] = val;
			ar[idx] = val;
			return ;
		}
		ll mid = (s + e)/2;
		if(mid >= idx)
		update(2*node, s, mid, idx, val);
		else
		update(2*node+1, mid+1, e, idx, val);
		merge(tree[node],tree[2*node], tree[2*node+1]);
	}
	
	struct data query(ll node, ll s, ll e, ll L, ll R){
		if(R<s || L>e){
			data sample;
			sample.mn = 1;
			return sample;
		}
		if(L<=s && R>=e){
			return tree[node];
		}
		ll mid = (s+e)/2;
		struct data l = query(2*node, s, mid, L, R);
		struct data r = query(2*node+1, mid+1, e, L, R);
		struct data ans;
		merge(ans,l,r);
		return ans;
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
  	ll n;
  	cin >> n;
	//while(cin >> n){
		ll q;
		SegTree S;
		S.init(n);
		for(ll i=1;i<=n;i++){
			cin >> S.ar[i].mn;
			if(S.ar[i].mn>0)
			S.ar[i].mn = 1;
			else if(S.ar[i].mn<0)
			S.ar[i].mn = -1;
			else
			S.ar[i].mn = 0;
			
		}
		cin >> q;
		S.build(1,1,n);
		while(q--){
			int type;
			cin >> type;
			ll l,r;
			cin >> l >> r;
			data ans;
			if(type == 1){
				ans = S.query(1,1,n,l,r);
				if(ans.mn>0)
				cout<<"+";
				else if(ans.mn<0)
				cout<<"-";
				else
				cout<<"0";
			}
			else{
				if(r>0)
				r = 1;
				else if(r<0)
				r = -1;
				else
				r = 0;
				ans.mn = r;
				S.update(1,1,n,l,ans);
			}
		}
		cout << "\n";
	//}
  	
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
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

int totalValue(int X, int mask){
	int total = 0;
	for(int i=0;i<X;i++){
		if((mask>>i)&1) total += i+1;
	}
	return total;
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
  */int T,D;
  	cin >> D >> T;
  	int cannot_remove = 0;
	while(T>2*D){
		cannot_remove += T;
		T--;
	}
	vector<double> roll_prob(2*D+1,0.0);
	vector<double> dp((1<<T)+1,0.0);
	for(int i=1;i<=D;i++){
	 	for(int j=1;j<=D;j++) {
			roll_prob[i+j] += 1.0/(D*D);
			//cout << setprecision(10) << fixed << showpoint;
			//cout << roll_prob[i+j] << " ";
		}
	}
	for(int token=0;token<(1<<T);token++){
		for(int roll=2;roll<=2*D;roll++){
			double best_expec_value = totalValue(T,token) * 1.0;
			for(int subset=1;subset<(1<<T);subset++){
				if(((token & subset) == subset) && (totalValue(T,subset) == roll)) 
					best_expec_value = min(best_expec_value,dp[subset ^ token]);
			}
			dp[token] += best_expec_value * roll_prob[roll];
		}
		//cout << token << " " << dp[token] << "\n";
	}
	int ans = dp[(1<<T)-1] + cannot_remove;  
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
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



void solve() {
  
    ll n,q;
	cin >> n >> q;
	queue<ll> ar[n+1];
	queue<pair<ll,ll>> Q;
	vector<bool> mark(3e5+1,0);
	ll unread=0,event=1;
	while(q--){
		ll t,x;
		cin >> t >> x;
		if(t==1){
			Q.push({event,x});
			ar[x].push(event);
			event++;
			unread++;
		}
		else if(t==2){
			while(!ar[x].empty()){
				ll v = ar[x].front();
				if(!mark[v]){
					mark[v] = 1;
					unread--;
				}
				ar[x].pop();
			}
		}
		else{
			while(!Q.empty() && Q.front().first <= x){
				pair<ll,ll> p = Q.front();
				if(!mark[p.first]){
					unread--;
					mark[p.first] = 1;
				}
				Q.pop();
			}
		}
		cout<<unread<<"\n";
	}
  	
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
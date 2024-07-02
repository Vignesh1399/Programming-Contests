#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n + 1), ans;
	set<ll> list;
	set<pair<ll,ll>> bad_pair;
	for(ll i = 1; i <= n; i++) {
		cin >> ar[i];
		list.insert(i);
	}
	for(ll i = 1; i <= n; i++) {
		if(i == 1 && __gcd(ar[i], ar[n]) == 1) {
			bad_pair.insert({n, 1});
		}
		else if(i > 1 && __gcd(ar[i], ar[i - 1]) == 1) {
			bad_pair.insert({i - 1, i});
		}
	}
	while(sz(bad_pair) > 0) {
		vector<pair<ll,ll>> temp_pairs;
		while(sz(bad_pair) > 0) {
			auto cur = *bad_pair.begin();
			auto pos = list.find(cur.S);
			auto right = pos;
			if(pos == list.begin()) {
				right = (++pos);
			}
			else if(pos == (--list.end())) {
				right = list.begin();
			}
			else {
				right = (++pos);
			}
			ans.eb(cur.S);
			list.erase(cur.S);
			bad_pair.erase(bad_pair.begin());
			if(bad_pair.find({cur.S, *right}) != bad_pair.end())
				bad_pair.erase({cur.S, *right});
			if(__gcd(ar[cur.F], ar[*right]) == 1)
				temp_pairs.pb({cur.F, *right});
		}
		for(auto i : temp_pairs) {
			if(list.find(i.F) != list.end() && list.find(i.S) != list.end())
				bad_pair.insert({i.F, i.S});
		}
	}
	cout << sz(ans) << " ";
	for(auto i : ans)
		cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t = 1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


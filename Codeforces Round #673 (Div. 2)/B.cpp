#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,t;
	cin >> n >> t;
	vector<pair<ll,ll>> ar(n);
	ll k=0;
	for(auto &i: ar){
		cin >> i.first;
		i.second = k++;
	}
	map<ll,ll> m;
	sort(ar.begin(),ar.end());
	vector<ll> b,c;
	for(ll i=0;i<n;i++){
		bool ok1 = binary_search(b.begin(),b.end(),t-ar[i].first);
		bool ok2 = binary_search(c.begin(),c.end(),t-ar[i].first);
		if(ok1 && ok2){
			auto l = equal_range(b.begin(),b.end(),t-ar[i].first);
			auto r = equal_range(c.begin(),c.end(),t-ar[i].first);
			if(l.second - l.first>r.second-r.first){
				c.eb(ar[i].first);
				m[ar[i].second] = 2;
			}
			else{
				b.eb(ar[i].first);
				m[ar[i].second] = 1;
			}
		}
		else if(ok1){
			c.eb(ar[i].first);
			m[ar[i].second] = 2;
		}
		else{
			b.eb(ar[i].first);
			m[ar[i].second] = 1;
		}
	}
	for(auto i : m){
		cout << i.second%2 << " ";
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


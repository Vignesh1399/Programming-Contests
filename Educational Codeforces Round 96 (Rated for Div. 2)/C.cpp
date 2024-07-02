#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<pair<ll,ll>> ans;
	vector<ll> ar;
	for(ll i=0;i<n;i++)
	ar.eb(i+1);
	while(sz(ar)>=2){
		ans.pb({ar.back(),ar[sz(ar)-2]});
		ll x1 = ar.back();
		ar.pop_back();
		x1 += ar.back();
		ar.pop_back();
		x1 = x1/2 + x1%2;
		ar.eb(x1);
	}
	cout << ar[0] << "\n";
	for(auto i : ans)
	cout << i.first << " " << i.second << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


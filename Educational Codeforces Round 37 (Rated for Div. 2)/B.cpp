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
	vector<pair<ll,ll>> ar(n+1);
	vector<ll> ans;
	ll st = 0;
	for(ll i=1;i<=n;i++){
		cin >> ar[i].F >> ar[i].S;
	}
	for(ll i=1;i<=n;i++){
		st = max(st,ar[i].F);
		if(st<=ar[i].S)
		ans.eb(st++);
		else
		ans.eb(0);
	}
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


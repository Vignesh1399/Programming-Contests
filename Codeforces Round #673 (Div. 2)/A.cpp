#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n);
	for(auto &I : ar){
		cin >> I;
	}
	sort(ar.begin(),ar.end());
	ll ans = 0;
	for(ll i=1;i<n;i++){
		ans += max((k-ar[i])/ar[0],0ll);
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


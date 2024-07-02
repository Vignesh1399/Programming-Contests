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
	vector<ll> ind(n+1,0);
	for(ll i=0;i<n-1;i++){
		ll a,b;
		cin >> a >> b;
		ind[b]++;
	}
	ll cnt = 0;
	for(ll i=1;i<=n;i++){
		cnt += (ind[i] == 0);
	}
	cout << max(cnt-1,0ll) << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


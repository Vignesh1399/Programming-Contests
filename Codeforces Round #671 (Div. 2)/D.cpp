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
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	sort(ar.begin(),ar.end(),greater<ll>());
	for(ll i=1;i<n-1;i+=2)
	swap(ar[i],ar[i+1]);
	ll ans = 0;
	for(ll i=1;i<n-1;i++){
		if(ar[i]<ar[i-1] && ar[i]<ar[i+1])
		ans++;
	}
	cout << ans << "\n";
	for(auto i : ar)
	cout << i << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


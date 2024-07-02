#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),pr(n+2,0),sf(n+2,0),final;
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<n+1;i++){
		pr[i] = __gcd(pr[i-1],ar[i]);
	}
	for(ll i=n;i>-1;i--){
		sf[i] = __gcd(sf[i+1],ar[i]);
	}
	for(ll i=1;i<=n;i++){
		final.pb(__gcd(pr[i-1],sf[i+1]));
	}
	ll ans=1;
	for(auto i:final){
		ans = (ans * i)/(__gcd(ans,i));
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


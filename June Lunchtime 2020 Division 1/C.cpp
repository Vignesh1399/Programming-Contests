#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll freq[1000001];
void solve(){
	ll n,x,ans=0;
	cin >> n >> x;
	vector<ll> ar(n+1,0),pr(n+1,0),fac;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		pr[i] = pr[i-1] + ar[i];
	}
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			fac.pb(i);
			fac.pb(x/i);
		}
		if(i*i == x)
		fac.pop_back();
	}
	for(auto len : fac){
		ll z = x/len;
		for(ll i=len;i<=n;i++){
			ll s = pr[i] - pr[i-len];
			if(s<z)
			freq[s]++;
		}
		for(ll i=len;i<=n;i++){
			ll s = pr[i] - pr[i-len];
			if(s<z)
			ans += freq[z-s];
		}
		for(ll i=len;i<=n;i++){
			ll s = pr[i] - pr[i-len];
			if(s<z)
			freq[s] = 0;
		}
	}
	fac.clear();
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


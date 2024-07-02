#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,p;
	cin >> n >> p;
	vector<ll> ar(n,0),ans;
	for(auto &i:ar)
	cin >> i;
	sort(ar.begin(),ar.end());
	for(ll x=1;x<=2000;x++){
		ll i=0,tx=x;
		for(i=0;i<n;i++){
			ll v = upper_bound(ar.begin(),ar.end(),tx) - ar.begin();
			tx++;
			if(v-i<=0 ||(v-i)%p==0)
			break;
		}
		if(i==n)
		ans.pb(x);
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,-1),m(n+1,0),ans;
	for(ll i=0;i<n;i++)
	cin >> ar[i];
	while(1){
		for(ll i=0;i<n;i++){
			m[ar[i]] = 1;
		}
		ll mex=1e9;
		for(ll i=0;i<=n;i++){
			if(!m[i]){
				mex = i;
				break;
			}
		}
		fill(m.begin(),m.end(),0);
		if(mex<n){
			ar[mex] = mex;
			ans.pb(mex);
			continue;
		}
		ll idx=n+1;
		for(ll i=0;i<=n;i++){
			if(ar[i] != i){
				idx = i;
				break;
			}
		}
		if(idx==n)
		break;
		ar[idx] = mex;
		ans.pb(idx);
	}	
	
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i+1 << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


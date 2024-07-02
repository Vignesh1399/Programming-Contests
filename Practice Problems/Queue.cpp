#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0),ans(n+1,0);
	vector<pair<ll,ll>> iar;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		iar.pb({ar[i],i});
	}
	sort(iar.begin(),iar.end());
	ll m = -1;
	for(ll i=0;i<sz(iar);i++){
		if(iar[i].second>=m){
			ans[iar[i].second] = -1;
		}
		else{
			ans[iar[i].second] = m - iar[i].second - 1;
		}
		m = max(m,iar[i].second);
	}
	for(ll i=1;i<=n;i++)
	cout << ans[i] << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


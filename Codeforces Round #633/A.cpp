#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,diff=0,cmax=-1e18;
	cin>>n;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >>ar[i];
	for(ll i=1;i<=n;i++){
		cmax = max(cmax,ar[i]);
		if(ar[i]<ar[i-1]){
			diff = max(diff,cmax - ar[i]);
		}
	}
	ll x = ceil(log2(diff+1));
	cout<<x;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


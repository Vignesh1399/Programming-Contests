#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll ans = 1e18;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(n/i<=k)
			ans = min(ans,i);
			else if(i<=k)
			ans = min(ans,n/i);
		}
	}
	cout<<ans<<"\n";	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


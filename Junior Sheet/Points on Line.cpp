#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,d,ans=0;
	cin >> n >> d;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=n;i++){
		ll len = upper_bound(ar.begin()+i,ar.end(),ar[i]+d) - ar.begin() - i;
		len--;
		ans += len*(len-1)/2; 
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


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,sum=0;
	cin>>n>>x;
	ll ans = 0;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar.begin()+1,ar.end(),greater<ll>());
	for(ll i=1;i<=n;i++){
		sum+=ar[i];
		if(x*i<=sum)
		ans = i;
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


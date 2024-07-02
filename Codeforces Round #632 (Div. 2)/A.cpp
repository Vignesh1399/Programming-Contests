#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	map<ll,ll> curs;
	cin >> n;
	vector<ll> ar(n+1,0),pr(n+1,0);
	for(ll i=1;i<=n;i++){
	cin >> ar[i];
	pr[i] = pr[i-1] + ar[i];
	}
	ll ans = 0;
	ll left = 0;
	for(ll i=1;i<=n;i++){
		if(pr[i] == 0 || curs[pr[i]])
		left = max(curs[pr[i]] + 1,left);
		ans += i - left;
		curs[pr[i]] = i;
		//cout<<pr[i]<<" "<<ans;
		//cout<<"\n";
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


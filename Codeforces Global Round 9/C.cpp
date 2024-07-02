#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll s = 1e9;
	bool f = 1;
	vector<ll> ar(n,0),ans;
	for(ll i=0;i<n;i++){
		cin >> ar[i];
		if(i==0)
		ans.pb(ar[i]);
		if(ar[i]!=1 && f){
			s = min(ar[i],s);
		}
		if(ar[i]==1){
			f = 0;
			if(s==1e9)
			s = 1;
			ans.pb(s);
		}
		if(i==n-1)
		ans.pb(ar[i]);
	}
	if(ans[0]<=max(ans[1],ans[2]) && ans[1]<=ans[2])
	cout << "YES\n";
	else
	cout <<"NO\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


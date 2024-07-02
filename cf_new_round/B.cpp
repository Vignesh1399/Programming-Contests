#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll ar[n+1],pr[n+1];
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=1;i<=n;i++){
		if(i == 1){
			pr[i] = !(ar[i]>ar[i+1]);
		}
		else{
			pr[i] = ar[i]>ar[i-1];
		}
		//cout << pr[i] << " ";
	}
	vector<ll> ans;
	for(ll i=1;i<=n;i++){
		if(i==1)
		ans.pb(ar[i]);
		else if(pr[i] != pr[i-1]){
		if(i!=2)
		ans.pb(ar[i-1]);
		if(i==n)
		ans.pb(ar[i]);
		}
		else if(i==n)
		ans.pb(ar[i]);
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


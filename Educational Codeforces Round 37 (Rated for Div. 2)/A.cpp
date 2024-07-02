#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define first F
#define second S
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar;
	for(ll i=1;i<=k;i++){
		ll a;
		cin >> a;
		ar.eb(a);
	}
	//sort(ar.begin(),ar.end());
	ll diff = 1;
	for(ll i=1;i<sz(ar);i++){
		diff = max(diff,(ar[i]-ar[i-1]+1)/2 + (ar[i]+ar[i-1]+1)%2);
	}
	if(1ll != ar[0]){
		diff = max(diff,ar[0]);
	}
	if(n != ar[sz(ar)-1]){
		diff = max(diff,n - ar[sz(ar)-1] + 1);
	}
	cout << diff <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


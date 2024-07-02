#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	map<ll,ll> x,y;
	for(ll i=0;i<4*n-1;i++){
		ll a,b;
		cin >> a >> b;
		x[a]++;
		y[b]++;
	}
	ll ansx,ansy;
	for(auto i : x){
		if(i.second%2)
		ansx = i.first;
	}
	for(auto i : y){
		if(i.second%2)
		ansy = i.first;
	}
	cout << ansx << " " << ansy << "\n";	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


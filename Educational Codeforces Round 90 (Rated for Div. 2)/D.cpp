#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n,0);
	ll sum = 0;
	for(ll i=0;i<n;i++){
		cin >> ar[i];
		if(i%2 == 0)
		sum += ar[i];
	}
	// Assuming reversal starts at even position
	ll revdiff = 0, maxrev=0;
	for(ll i=1;i<n;i+=2){
		revdiff += ar[i]-ar[i-1];
		maxrev = max(maxrev,revdiff);
		revdiff = max(revdiff,0ll);
	}
	// Assuming reversal starts at odd position
	revdiff = 0;
	for(ll i=2;i<n;i+=2){
		revdiff += ar[i-1]-ar[i];
		maxrev = max(maxrev,revdiff);
		revdiff = max(revdiff,0ll);
	}
	cout << sum + maxrev << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


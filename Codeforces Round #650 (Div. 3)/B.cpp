#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,evens=0,odds=0;
	cin >> n;
	vector<ll> ar(n+1,0);
	for(ll i=0;i<n;i++){
		cin >> ar[i];
		if(i%2 != ar[i]%2){
			if(i%2)
			evens++;
			else
			odds++;
		}
	}
	if(evens != odds){
		cout << -1;
	}
	else
	cout << evens;
	
	cout << "\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


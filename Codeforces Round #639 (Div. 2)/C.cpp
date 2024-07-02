#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	set<ll> s;
	cin >> n;
	for(ll i=0;i<n;i++){
		ll x;
		cin >> x;
		if(x<0)
		x += -n*(x/n - 1);
		s.insert((i+x%n)%n);
	}
	if(sz(s) == n)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


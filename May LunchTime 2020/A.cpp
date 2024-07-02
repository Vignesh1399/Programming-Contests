#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll p,sum=0;
	ll val = 24*5;
	vector<ll> ar(6,0);
	for(ll i=1;i<=5;i++){
		cin >> ar[i];
	}
	cin >> p;
	for(ll i=1;i<=5;i++){
		sum += ar[i]*p;
	}
	if(sum >val)
	cout<<"Yes";
	else
	cout<<"No";
	cout <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


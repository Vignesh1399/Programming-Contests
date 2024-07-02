#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b;
	cin >> a >> b;
	map<ll,string> m;
	m[0] = m[1] = "Masha";
	if(a>b)
	m[1] = "Dasha";
	else
	m[0] = "Dasha";
	ll large = max(a,b);
	ll small = a+b-large;
	ll val = (a*b)/__gcd(a,b);
	ll l=0,s=0;
	for(ll i=large;i<=val;i+=large){
		l += i%small; 
		if(i%small == 0)
		l += small;
		//cout<<l<<" ";
	}
	s = val - l;
	if(l==s)
	cout<<"Equal";
	else
	cout<<m[l>s];
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


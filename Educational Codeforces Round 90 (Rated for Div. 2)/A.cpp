#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a>c)
	cout << -1 << " " << 1 ;
	else if(a==c)
	cout << -1 << " " << b;
	else{
		ll n =  c/a+1;
		if(n<=b)
		cout << 1 << " " << n ;
		else
		cout << 1 << " " << -1;
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


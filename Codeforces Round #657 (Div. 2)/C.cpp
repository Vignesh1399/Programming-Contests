#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll LCM(ll x, ll y){
	return x /__gcd(x,y) * y;
}

void solve(){
	ll ans = 1;
	for(ll i=2;i<=99;i++){
		ans = LCM(ans,i);
	}
	string s = to_string(ans);
	cout << sz(s);
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


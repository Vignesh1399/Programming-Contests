#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll num_resistors(ll a, ll b){
	if(b==0)
	return b;
	return a/b + num_resistors(b,a%b);
}

void solve(){
	ll a,b;
	cin >> a >> b;
	ll ans = num_resistors(max(a,b),min(a,b));
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


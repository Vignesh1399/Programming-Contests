#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a;
	long double b1;
	cin >> a >> b1;
	ll b = (long long)(b1 * 100 + 0.5);
	ll ans = (a * b)/(100);
	cout << ans; 
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


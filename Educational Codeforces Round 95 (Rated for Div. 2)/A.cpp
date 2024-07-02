#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll x,y,k;
	cin >> x >> y >> k;
	ll ans = k + (k*(y+1)-1)/(x-1) + ((k*(y+1)-1)%(x-1)>0);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


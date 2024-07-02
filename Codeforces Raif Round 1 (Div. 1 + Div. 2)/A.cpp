#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll x,y,a,b;
	cin >> x >> y >> a >> b;
	ll ans  = abs(a-x) + abs(b-y);
	if(abs(a-x)>0 && abs(b-y)>0)
	ans += 2;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


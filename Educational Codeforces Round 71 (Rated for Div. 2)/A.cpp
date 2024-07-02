#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll b,p,f,h,c;
	cin >> b >> p >> f;
	cin >> h >> c;
	ll ans = 0;
	if(c>h){
		swap(h,c);
		swap(p,f);
	}
	ll x = min(b/2,p);
	b -= 2*x;
	ans += x*h;
	ll y = min(b/2,f);
	b -= 2*y;
	ans += y*c;
	cout << ans << '\n';
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


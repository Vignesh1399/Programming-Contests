#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	long double ans,pi;
	pi = 2*acos(0);
	n *= 2;
	ans = 1/tan(pi/n);
	cout << setprecision(10) << fixed << ans << '\n';
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


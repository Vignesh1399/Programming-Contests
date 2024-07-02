#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll ar[7];
	for(ll i=1;i<=6;i++)
	cin >> ar[i];
	ll x = (ar[1] + ar[2] + ar[3]);
	ll big_triangle = x*x;
	ll small_triangles = ar[1]*ar[1] + ar[5]*ar[5] +ar[3]*ar[3];
	ll ans = big_triangle - small_triangles;
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


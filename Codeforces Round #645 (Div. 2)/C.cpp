#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll ans = (x2-x1) *(y2-y1) + 1;
	cout << ans <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


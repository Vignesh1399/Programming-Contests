#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b,n;
	cin >> a >> b >> n;
	ll x = max(a,b),y = min(a,b);
	ll op=0;
	while(x<=n){
		y += x;
		swap(x,y);
		op++;
	}
	cout << op << "\n";
	
}

int main() {
    FAST;
    ll t=1;
	cin>>t;
    while(t--) solve();	
    return 0;
}


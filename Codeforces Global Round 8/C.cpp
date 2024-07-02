#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	cout << 3*n + 4 << "\n";
	cout << 0 << " " << 0 << "\n" << 0 << " " << 1 << "\n";
	ll x,y;
	for(x=1,y=0;x<=n;x++,y++){
		cout << x << " " << y << "\n";
		cout << x << " " << y+1 << "\n";
		cout << x << " " << y+2 << "\n";
	}
	cout << x << " " << y << "\n";
	cout << x << " " << y+1 << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	if(b>=a)
	cout << b;
	else{
		if(c<=d)
		cout << -1;
		else{
			ll x = (a-b)/(c-d) + ((a-b)%(c-d)>0);
			cout << b + x*c;
		}
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


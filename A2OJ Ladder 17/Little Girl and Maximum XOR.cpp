#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll l,r;
	cin >> l >> r;
	for(ll i=60;i>=0;i--){
		bool b = (l>>i) & 1;
		bool c = (r>>i) & 1;
		if(b!=c){
			cout<<(1ll<<(i+1)) - 1ll;
			return ;
		}
	}
	cout<<0;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


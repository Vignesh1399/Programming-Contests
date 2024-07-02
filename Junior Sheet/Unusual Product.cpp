#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x;
	string ans = "";
	cin >> n;
	ll dia = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> x;
			if(i==j)
			dia = (dia + x)%2;
		}
	}
	ll q;
	cin >> q;
	while(q--){
		ll type,detail;
		cin >> type;
		if(type == 3){
			char ch = '0' + dia;
			ans += ch;
			continue;
		}
		else{
			cin >> detail;
			dia = (dia + 1)%2;
		}
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


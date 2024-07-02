#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll x1,y1,x2,y2,n,a,b,c,steps=0;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a >> b >> c;
		ll v1 = a*x1 + b*y1 + c;
		ll v2 = a*x2 + b*y2 + c;
		if(v1<0 && v2>0 || v2<0 && v1>0)
		steps++;
	}
	cout<<steps;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


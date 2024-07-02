#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,y;
	cin >> x >> y;
	ll temp = max(x,y);
	x = min(x,y);
	y = temp;
	setprecision(6);
	cout << fixed << showpoint;
	cin >> n;
	vector<double> ar(n+1,0),pr(n+1,0);
	ll dtrend=0,utrend=0;
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=n;i++){
		pr[i] = pr[i-1] + ar[i];
	}
	ll ans=0;
	for(ll i=y;i<=n;i++){
		double slow = (pr[i] - pr[i-y])/y; 
		double fast = (pr[i] - pr[i-x])/x;
		if(fast-slow>0){
			dtrend = 1;
		if(utrend==1) ans++;
			utrend = 0;
		}
		if(slow-fast>0){
			utrend = 1; 
			if(dtrend==1) ans++;
			dtrend = 0; 
		}
	}
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


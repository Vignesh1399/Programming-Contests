#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	// fix 4's bs on number of 7 sevens
	ll mx = 1e9, my = 1e9;
	for(ll i=0;i<=25e4;i++){
		ll y = -1;
		ll lb = 0, ub = 25e4;
		while(lb<=ub){
			ll mid = (lb + ub)/2;
			ll val  = 4*i + 7*mid;
			if(val == n){
				y = mid;
				break;
			}
			else if(val > n){
				ub = mid-1;
			}
			else
			lb = mid + 1;
		}
		if(y != -1){
			if(y+i<mx+my){
				mx = i;
				my = y;
			}
		}
	}
	if(mx == 1e9 && mx == 1e9)
	cout << -1;
	else{
		for(ll i=0;i<mx;i++)
		cout << 4;
		for(ll i=0;i<my;i++)
		cout << 7;
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


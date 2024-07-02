#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll extra=0;

ll findn(ll n){
	ll lb = 0, ub = 1e5;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		ll val = (mid*(3*mid+1))/2;
		if(val == n)
		return mid;
		else if(val<n)
		lb = mid+1;
		else
		ub = mid-1;
	}
	return ub;
}

void solve(){
	ll n,m,x=0;
	cin >> n;
	ll ans = findn(n);
	if(ans>0)
	x++;
	extra = n - (ans*(3*ans+1))/2;
	while(extra>1){
		ll temp = findn(extra);
		ans += temp;
		extra -= (temp*(3*temp+1))/2;
		x++;
	}
	cout<<x;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


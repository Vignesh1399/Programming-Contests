#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n;
	ll half = (n*(n+1))/2;
	if(half%2){
		cout << 0 << "\n";
		return ;
	}
	else
	half /= 2;
	ll lb = 1, ub = n;
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		ll diff = half - (mid*(mid+1))/2;
		if(diff<0)
		ub = mid-1;
		else
		lb = mid+1;
	}
	ll r = ub;
	lb = 1, ub = n;
	//cout << lb << " " << ub << " ";
	while(lb<=ub){
		ll mid = (lb+ub)/2;
		ll diff = half - (mid*(mid+1))/2;
		ll x = 1+diff, y = mid+diff;
		if(diff<=0 || (min(n,y) - max(x,mid+1) + 1) > 0)
		ub = mid-1;
		else
		lb = mid+1;
	}
	ll l = lb;
	//cout << l << " " << r << " ";
	for(ll i=l;i<=r && i>0;i++){
		ll diff = half - (i*(i+1))/2;
		if(diff == 0)
		ans += (i*(i-1))/2 + ((n-i)*(n-i-1))/2;
		else if(diff>0){
			ll x = 1+diff, y = i+diff;
			ans += max(0ll,min(n,y) - max(x,i+1) + 1);
		}
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


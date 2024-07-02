#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k,l1,r1,l2,r2;
	cin >> n >> k;
	cin >> l1 >> r1 >> l2 >> r2;
	ll noov = max(r1,r2) - min(l1,l2) - (r1-l1+r2-l2);
	ll curov = max(-noov,0ll);
	//cout << curov << " "; 
	//cout << noov << " ";
	ll extend;
	if(curov==0)
	extend = max(l1,l2) - min(l1,l2) + max(r1,r2) - max(l1,l2);
	else
	extend = max(l1,l2) - min(l1,l2) + max(r1,r2) - min(r1,r2);
	//cout << extend << " ";
	if(curov*n>=k){
		cout << 0 << "\n";
		return ;
	}
	ll mul = 1;
	for(ll i=1;i<=n;i++){
		if(curov*n+extend*i>=k){
			mul = i;
			break;
		}
		mul = i+1;
	}
	if(mul<=n){
		//cout << 2 << " ";
		ll ans = min(k - curov*n + mul*noov, (mul-1)*(noov+extend) + 2*(k-curov*n-extend*(mul-1)));
		cout << ans << "\n";
		return ;
	}
	ll left = k - curov*n - extend*n;
	cout << 2*left + (extend+noov)*n << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


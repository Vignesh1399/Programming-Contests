#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,a;
	cin >> n >> a;
	ll s=0;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		s += ar[i];
	}
	if(n==1){
	cout<<ar[1] - 1;
	return ;
	}
	for(ll i=1;i<=n;i++){
		ll left = a - s + ar[i];
		ll right = a - n + 1;
		left = max(left,1ll);
		right = min(ar[i],right);
		cout<<max(ar[i] - (right - left +1),0ll)<<" ";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


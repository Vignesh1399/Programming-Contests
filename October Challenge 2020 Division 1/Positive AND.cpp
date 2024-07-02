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
	vector<ll> ans = {2,3,1,5,4};
	if(n == 1){
		cout << 1 << "\n";
		return ;
	}
	if((n&(n-1)) == 0){
		cout << -1 << "\n";
		return ;
	}
	for(ll i=6;i<=n;i++){
		ans.eb(i);
	}
	for(ll i=6;i<n;i++){
		if((i&(i-1)) == 0)
		swap(ans[i-1],ans[i]);
	}
	for(ll i=0;i<n;i++)
	cout << ans[i] << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


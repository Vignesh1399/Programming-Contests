#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x;
	cin >> n >> x;
	ll ar[n+1];
	ll sum=0,ans=0;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		sum += ar[i];
		if(sum %x != 0)
		ans = i;
	}
	sum = 0;
	for(ll i=n;i>=1;i--){
		sum += ar[i];
		if(sum%x != 0)
		ans = max(ans,n-i+1);
	}
	if(ans)
	cout << ans;
	else
	cout <<-1;
	cout << "\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


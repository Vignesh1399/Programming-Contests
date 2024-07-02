#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0),pr(2*k+2,0),final(2*k+2,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	for(ll i=1;i<=n/2;i++){
		ll x = min(ar[i],ar[n-i+1]);
		ll y = max(ar[i],ar[n-i+1]);
		pr[2]+=2;
		pr[x+1]-=2;
		pr[x+1]++;
		pr[ar[i]+ar[n-i+1]]--;
		pr[ar[i]+ar[n-i+1]+1]++;
		pr[y+k+1]--;
		pr[y+k+1]+=2;
	}
	ans = 1e18; 
	for(ll i=2;i<=2*k;i++){
		final[i] = final[i-1] + pr[i];
		ans = min(final[i],ans);
	}
	cout<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


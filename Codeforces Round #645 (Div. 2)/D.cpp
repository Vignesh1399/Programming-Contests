#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,ans=0;
	cin >> n >> x;
	n *= 2;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n/2;i++){
		cin >> ar[i];
		ar[i+n/2] = ar[i];
	}
	vector<ll> days(n+1,0),hugs(n+1,0);
	for(ll i=1;i<=n;i++){
		days[i] = days[i-1] + ar[i];
		hugs[i] = hugs[i-1] + (ar[i]*(ar[i]+1))/2;
	}
	for(ll i=1;i<=n;i++){
		if(days[i]<x) continue;
		ll left = upper_bound(days.begin(),days.end(),days[i]-x) - days.begin();
		ll total_hugs = hugs[i] - hugs[left];	
		ll part_days = x - days[i] + days[left];
		total_hugs += hugs[left] - hugs[left-1] - ((ar[left] - part_days)*(ar[left] - part_days + 1))/2;
		ans = max(ans,total_hugs);
		//cout << left << " " << part_days <<"\n";
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


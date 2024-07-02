#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> ar(n+1,0);
	vector<bool> check(m+1,0);
	ll cnt = 0,cnt1=0;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(ar[i]<m){
			check[ar[i]] = 1;
			cnt1++;
		}
		if(ar[i]>m)
		cnt++;
	}
	for(ll i=1;i<=m-1;i++){
		if(!check[i]){
			cout << -1 << "\n";
			return ;
		}
	}
	cout << cnt + cnt1 << "\n";	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


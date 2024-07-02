#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;


void solve(){
	ll n,ans=0,k;
	cin >> n >> k;
	ans = (ans + (n*(n+1))%MOD)%MOD;
	if((k-1)%2)
	ans = (ans + ((k-1)%2)*k)%MOD;
	ll x = (k-1)/2;
	ll temp = (2*x)%MOD;
	ll temp1 = (((2*n)%MOD) + ((1+x)%MOD))%MOD;
	temp = (temp*temp1)%MOD;
	ans = (ans + temp)%MOD;
	if(k==1){
		ans=0;
		ans = (ans + (n*(n-1))%MOD)%MOD;
		ans = (ans + n)%MOD;
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


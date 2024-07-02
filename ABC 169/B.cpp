#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,i;
	cin >> n;
	ll m = 1e18;
	ll prod = 1;
	bool flag = 0,z=0;
	for(i=1;i<=n;i++){
		ll a;
		cin >> a;
		z += (a==0);
		if (a && prod > m/a){
			//cout << i << " "; 
			flag = 1;
		}
		prod *= a;
	}
	if(z)
	cout <<0;
	else if(!flag)
	cout << prod;
	else
	cout << -1;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


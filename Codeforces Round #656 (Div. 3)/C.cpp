#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+2,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	//ll pr = 0;
	ll i,j,c=0;
	for(i=n;i>=1;i--){
		if(ar[i]<ar[i+1])
		break;
	}
	for(j=i;j>=1;j--){
		if(ar[j]>ar[j+1])
		break;
	}
	cout << j << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


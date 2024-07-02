#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,m;
	ll one = 0, z= 0;
	cin >> n ;
	vector<ll> ar(n+1,0),br(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=1;i<=n;i++){
		cin >> br[i];
		if(br[i]) one++;
		else z++;
	}
	bool flag = 0;
	for(ll i=1;i<=n;i++){
		if(ar[i]<ar[i-1]) flag=1;
	}
	if(one>0 && z>0)
	cout << "Yes";
	else {
		if(flag)
		cout << "No";
		else
		cout <<"Yes";
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


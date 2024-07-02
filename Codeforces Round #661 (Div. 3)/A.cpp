#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n ;
	vector<ll> ar(n+1,0);
	for(ll i=0;i<n;i++){
		cin >> ar[i+1];
	}
	sort(ar.begin(),ar.end());
	for(ll i=2;i<=n;i++){
		if(ar[i]-ar[i-1]>1){
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


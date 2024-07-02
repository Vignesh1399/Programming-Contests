#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x;
	cin >> n >> x;
	vector<ll> ar(n),br(n);
	for(ll i=0;i<n;i++){
		cin >> ar[i];
	}
	for(ll i=0;i<n;i++){
		cin >> br[i];
	}
	sort(ar.begin(),ar.end());
	sort(br.begin(),br.end(),greater<ll>());
	for(ll i=0;i<n;i++){
		if(ar[i]+br[i]>x){
			cout << "No\n";
			return ;
		}
	}
	cout << "Yes\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


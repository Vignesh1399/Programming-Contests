#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(2*n+1,0);
	vector<ll> odd,eve;
	for(ll i=1;i<=2*n;i++){
		cin >> ar[i];
		if(ar[i]%2)
		odd.pb(i);	
		else
		eve.pb(i);
	}
	if(sz(odd)%2){
		odd.pop_back();
		eve.pop_back();
	}
	else if(sz(eve)>sz(odd)){
		eve.pop_back();
		eve.pop_back();
	}
	else{
		odd.pop_back();
		odd.pop_back();
	}
	for(ll i=1;i<sz(odd);i+=2){
		cout << odd[i-1] << " " << odd[i] << "\n";
	}
	for(ll i=1;i<sz(eve);i+=2){
		cout << eve[i-1] << " " << eve[i] << "\n";
	}
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


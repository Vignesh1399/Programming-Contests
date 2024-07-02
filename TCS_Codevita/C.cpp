#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9+7;

void solve(){
	ll low,high,k;
	cin >> low >> high >> k;
	if(k==0){
		cout << 0 ;
		return ;
	}
	ll odd=0,eve=0;
	vector<ll> osum(k+1,0),esum(k+1,0);
	esum[0] = 1;
	if(low%2){
		odd = (high-low+1)/2 +(high-low+1)%2;
		eve = (high-low+1-odd);
	}
	else{
		odd = (high-low+1)/2 +(high-low+1)%2;
		eve = (high-low+1-odd);
		swap(odd,eve);
	}
	//odd %= MOD;
	//eve %= MOD;
	for(ll i=1;i<=k;i++){
		//osum[i] = ((esum[i-1] * odd)%MOD + (osum[i-1]* eve)%MOD)%MOD;
		//esum[i] = ((esum[i-1] * eve)%MOD + (osum[i-1]* odd)%MOD)%MOD;
		osum[i] = ((esum[i-1] * odd) + (osum[i-1]* eve));
		esum[i] = ((esum[i-1] * eve) + (osum[i-1]* odd));
	}
	ll ans =  esum[k];
	cout << ans ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


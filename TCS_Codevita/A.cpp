#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

string Tobinary(ll n,ll cnt,ll m){
	string ans = "";
	if(n==0){
		for(ll i=0;i<cnt;i++){
			ans += '0' + ((n>>i) & 1);
		}
		reverse(ans.begin(),ans.end());
		ans = '0'+ans;
		return ans;
	}
	for(ll i=0;i<cnt;i++){
		ans += '0' + ((n>>i) & 1); 
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n,0);
	for(auto &i : ar)
	cin >> i;
	ll tm = *max_element(ar.begin(),ar.end());
	ll cnt = 0;
	ll m = tm;
	while(m>0){
		m/=2;
		cnt++;
	}
	ll ans = 0;
	for(ll i=1;i<(1ll<<n);i++){
		ll ones=0,total=0;
		for(ll j=0;j<n;j++){
			if((i>>j) & 1){
				ones += __builtin_popcountll(ar[j]);
				total += cnt;
			}
		}
		if((total%2 == 0) && (ones == total/2))
			++ans;
	}
	string s = Tobinary(ans,cnt,tm);
	cout << s ;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


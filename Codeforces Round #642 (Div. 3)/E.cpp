#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	string s;
	cin >> n >> k;
	cin >> s;
	vector<ll> pr(n+1,0), dp(n+1,0);
	ll t1 = 0,ans=n;
	for(auto i:s){
		t1 += (i=='1');
	}
	for(ll i=0;i<k;i++){
		ll all_zeros = 0, ending_one=0,ending_zero=0;
		for(ll j=i;j<n;j+=k){
			ending_zero = (s[j] == '1') + min(ending_one,ending_zero);
			ending_one = (s[j] == '0') + min(ending_one,all_zeros);
			all_zeros += (s[j] == '1');
		}
		ans = min({ans,ending_one + t1 - all_zeros,t1,ending_zero + t1 - all_zeros});
	}
	cout<<ans<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll k;
	cin >> k;
	vector<ll> cnt(11,1);
	string s = "codeforces";
	ll cur_prod = 1,idx=0;
	while(cur_prod < k){
		cnt[idx]++;
		cur_prod = 1;
		for(ll i=0;i<10;i++)
		cur_prod *= cnt[i];
		idx++;
		idx %= 10;
	}
	for(ll i=0;i<10;i++){
		while(cnt[i]--)
		cout << s[i];
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


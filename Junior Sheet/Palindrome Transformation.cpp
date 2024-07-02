#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,p,ans=0;
	cin >> n >> p;
	string s;
	cin >> s;
	s = s[0] + s ;
	ll left = n+1,right=0;
	if(p>n/2){
		p = n-p+1;
		reverse(s.begin()+1,s.end());
	}
	for(ll i=1;i<=n/2;i++){
		ll val = min(26 - abs(s[i] - s[n-i+1]),abs(s[i] - s[n-i+1]));
		ans += val;
		if(val>0){
		left = min(left,i);
		right = max(right,i);
		}
	}
	if(p>=right && ans>0)
	ans += abs(p-left);
	else if(ans>0 && p<=left)
	ans += abs(p-right);
	else if(ans>0)
	ans += 2*(min(p-left,right-p)) + max(p-left,right-p);
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


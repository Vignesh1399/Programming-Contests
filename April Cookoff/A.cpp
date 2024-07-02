#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string s,r;
	cin >> s >> r;
	ll left=1e8,right=0,ans=1e18;
	vector<ll> ar,br;
	for(ll i=0;s[i];i++){
		if(s[i]!=r[i]){
		left = i;
		break;
		}
	}
	for(ll i=s.length()-1;i>=0;i--){
		if(s[i]!=r[i]){
			right = i;
			break;
		}
	}
	for(ll i=0;s[i];i++){
		if(s[i]!=r[i])
		ar.pb(i);
	}
	br.pb(1e18);
	for(ll i=1;i<sz(ar);i++){
		br.pb(ar[i] - ar[i-1]);
	}
	ll cur = right - left + 1;
	sort(br.begin(),br.end(),greater<ll>());
	br[0] = 0;
	for(ll k=1;k<=sz(ar);k++){
		ans = min(ans,(cur - br[k-1])*k);
		cur -= br[k-1];
		cout<<ans<<"\n";
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


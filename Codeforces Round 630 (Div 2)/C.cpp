#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<vector<ll>> pos(n+1,vector<ll> (27,0));
	vector<ll> apos(n+1,0);
	string s;
	cin>>s;
	for(ll j=0;j<n;j+=k){
		for(ll i=0;i<k/2;i++){
			pos[i][s[i+j] - 'a']++;
			pos[i][s[j+k-i-1] - 'a']++;
		}
		if(k%2)
		pos[k/2][s[j + k/2] - 'a']++;
	}	
	ll change = 0;
	for(ll i=0;i<k/2;i++){
		ll total = 0;
		for(ll j=0;j<26;j++){
			apos[i] = max(apos[i],pos[i][j]);
			total += pos[i][j];
		}
		change += total - apos[i];
	}
	if(k%2){
		ll total = 0;
		for(ll j=0;j<26;j++){
			total += pos[k/2][j];
			apos[k/2] = max(apos[k/2],pos[k/2][j]);
		}
		change += total - apos[k/2];
	}
	cout<<change<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


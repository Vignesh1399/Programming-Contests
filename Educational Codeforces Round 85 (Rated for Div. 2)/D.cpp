#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,left,right;
	cin >> n >> left >> right;
	ll vertices = right - left + 1;
	vector<ll> terms(1,0);
	ll t = 2*(n-1);
	ll x = 1,k = 0;
	while(t>0){
		terms.pb(t+terms[k++]);
		t -= 2;
		if(terms[k-1]<left && terms[k]<=right)
		x = k;
	}
	terms.pb(1ll+terms[k++]);
	if(terms[k-1]<left && terms[k]<=right)
	x = k;
	for(ll j=x;j<=k;j++){
		while(vertices>0 && (left - terms[j-1])>0 && left<=terms[j]){
			if(j==k)
			cout<<1ll<<" ";
			else if((left - terms[j-1])%2)
			cout<<j<<" ";
			else
			cout<<j + (left-terms[j-1])/2<<" ";
			left++;
			vertices--;
		}
		if(vertices<1)
		break;
	}
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	bool ok = (find(ar.begin()+1,ar.end(),k) != ar.end()) ? 1:0;
	bool ok2=0;
	for(ll i=1;i<=n-2;i++){
		ll cnt2=0;
		for(ll j=i;j<=i+2;j++){
			if(ar[j]>=k)
			cnt2++;
		}
		if(cnt2>=2){
			ok2=1;
			break;
		}
	}
	for(ll i=1;i<=n-1;i++){
		ll cnt2=0;
		for(ll j=i;j<=i+1;j++){
			if(ar[j]>=k)
			cnt2++;
		}
		if(cnt2>=2){
			ok2=1;
			break;
		}
	}
	if(n==1 && ok)
	cout<<"yes";
	else if(ok && ok2)
	cout<<"yes";
	else
	cout<<"no";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


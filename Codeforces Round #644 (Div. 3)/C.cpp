#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,-1);
	ll o=0,e=0;
	for(ll i=1;i<=n;i++){
	cin >> ar[i];
	if(ar[i]%2)
	o++;
	else
	e++;
	}
	bool yes=0;
	sort(ar.begin(),ar.end());
	for(ll i=1;i<=n;i++){
		if(ar[i] - ar[i-1] == 1)
		yes=1;
	}
	if(o%2==1 && yes)
	cout<<"YES";
	else if(e%2==0)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<"\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


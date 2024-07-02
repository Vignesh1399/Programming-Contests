#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	if((n/2)%2){
	cout<<"NO\n";
	return ;
	}
	cout<<"YES\n";	
	for(ll i=1;i<=n/2;i++)
	cout<<4*i-2<<" ";
	for(ll i=1;i<=n/2;i++){
		if(i%2)
		cout<<4*i-1<<" ";
		else
		cout<<4*i - 3<<" ";
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


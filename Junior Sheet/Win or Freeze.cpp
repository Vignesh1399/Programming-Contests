#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ans;
	ll temp = n;
	for(ll i=2;i*i<=temp;i++){
		while(n%i==0){
			ans.pb(i);
			n/=i;
			//cout << i <<" ";
		}
		if(sz(ans) > 2)
		break;
	}
	if(n>1 && n!=temp)
	ans.pb(n);
	if(!sz(ans))
	cout<<1<<"\n"<<0;
	else if(sz(ans)>2)
	cout<<1<<"\n"<<ans[0]*ans[1];
	else
	cout<<2;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


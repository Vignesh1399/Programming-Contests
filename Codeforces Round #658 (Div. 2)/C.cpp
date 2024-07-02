#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	vector<ll> ans;
	for(ll i=0;i<n;i++){
		if(a[i] != b[i])
			ans.insert(ans.end(),{i+1,1,i+1});
	}
	cout << sz(ans) << " ";
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string z = "";
	string s;
	cin >> s;
	vector<string> ans;
	for(ll i=s.length()-1;i>=0;i--){
		if(s[i]!= '0')
		ans.pb(s[i]+z);
		z += "0";
	}
	cout<<sz(ans)<<"\n";
	for(auto i:ans)
	cout<<i<<" ";
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


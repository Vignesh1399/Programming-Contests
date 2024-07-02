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
	map<char,ll> m;
	cin >> a >> b;
	for(ll i=0;a[i];i++)
	m[a[i]]++;
	vector<vector<ll>> ans;
	for(char ch = 'z';ch >='a';ch--){
		if(m[ch] == 0) continue;
		if(a == b)
		break;
		ans.pb(vector<ll>());
		ll x=0;
		for(ll i=0;a[i];i++){
			if(b[i] == ch && a[i] > ch){
			ans.back().pb(i);
			m[ch]++;
			m[a[i]]--;
			//cout << ch <<" "<< a[i] <<" ";
			a[i] = ch;
			}
			else if(a[i] == ch){
				ans.back().pb(i);
				x++;
			}
		}
		if(sz(ans)>0 && sz(ans.back())==0)
		ans.pop_back();
		else if(sz(ans.back()) == x)
		ans.pop_back();
	}
	if(a.compare(b) == 0){
		cout << sz(ans)<<"\n";
		for(ll i=0;i<sz(ans);i++){
			cout << sz(ans[i]) <<" ";
			for(ll j=0;j<sz(ans[i]);j++){
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	cout << -1 <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


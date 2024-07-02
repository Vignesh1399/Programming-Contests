#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll k=1;
	vector<ll> ans;
	set<ll> s0,s1;
	for(ll i=0;s[i];i++){
		if(i==0){
			ans.pb(k);
			if(s[i] == '1')
				s1.insert(k);
			else
				s0.insert(k);
		}
		else if(s[i] != s[i-1]){
			ans.pb(k);
			if(s[i] == '0'){
				s0.insert(k);
				s1.erase(k);
			}
			else{
				s1.insert(k);
				s0.erase(k);
			}
		}
		else{
			if(s[i] == '1' && sz(s0)){
				k = *s0.begin();
				ans.pb(k);
				s1.insert(k);
				s0.erase(k);
			}
			else if(s[i] == '0' && sz(s1)){
				k = *s1.begin();
				ans.pb(k);
				s0.insert(k);
				s1.erase(k);
			}
			else{
				k = k+1;
				if(s[i] == '1')
				s1.insert(k);
				else
				s0.insert(k);
				ans.pb(k);
			}
		}
	}
	cout << *max_element(ans.begin(),ans.end())<< "\n";
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


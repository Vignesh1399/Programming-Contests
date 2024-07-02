#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
class StringReduction{
	public:
	string reduce(string &s, ll k){
		stack<pair<char,ll>> st;
		for(ll i=0;s[i];i++){
			if(st.empty())
			st.push({s[i],1});
			else if(st.top().F == s[i]){
				ll x = st.top().S;
				st.pop();
				st.push({s[i],x+1});
			}
			else{
				st.push({s[i],1});
			}
			while(!st.empty() && st.top().S>=k){
				pair<char,ll> x = st.top();
				st.pop();
				if(x.S > k){
					st.push({x.F,x.S-k});
				}
			}
		}
		string ans = "";
		while(!st.empty()){
			while(st.top().S--)
			ans += st.top().F;
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		return ans;
	}
};
void solve(){
	string s;
	ll k;
	cin >> s >> k;
	StringReduction sr;
	string ans = sr.reduce(s,k);
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct KMP {
	string s,pat; // string s, pattern pat
	ll n; // Length of string
	ll m; // Length of pattern
	vector<ll> pi; // Prefix function
	
	/* 
		pi(i) --- Longest proper Prefix of pat[0..i] which is
		also a suffix of pat[0..i] 
		By definition : pi(0) = 0
	*/
	
	// Initialise String Pattern and Lengths
	void init(string myString, string myPattern){
		s = myString;
		pat = myPattern;
		n = s.length();
		m = pat.length();
		pi.resize(m,0);
	}
	
	// Building Prefix Function
	void buildPrefix(){
		for(ll i=1;i<m;i++){
			ll curpi = pi[i-1];
			while(curpi > 0 && pat[curpi] != pat[i])
				curpi = pi[curpi-1];
			if(pat[curpi] == pat[i])
				pi[i] = curpi + 1;
			else
				pi[i] = curpi;
		}
	}
	
	// String Matching -- Change Return Type According to Type of Match
	ll match(){
		ll ans = 0,match_len = 0;
		for(ll i=0;i<n;i++){
			if(match_len < m && s[i] == pat[match_len])
				match_len++;
			else if(match_len > 0){
				ll curlen = pi[match_len-1];
				while(curlen > 0 && pat[curlen] != s[i])
					curlen = pi[curlen - 1];
				if(pat[curlen] == s[i])
					curlen++;
				match_len = curlen;
			}
			if(match_len == m)
				ans++;
		}
		return ans;
	}
};

void solve(){
	string s,pat;
	ll ans;
	cin >> s >> pat;
	struct KMP kmp;
	kmp.init(s,pat);
	kmp.buildPrefix();
	ans = kmp.match();
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


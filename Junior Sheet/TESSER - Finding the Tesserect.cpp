#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> calculate_pi(string &s){
	vector<ll> pi(sz(s),0);
	for(ll i=1;s[i];i++){
		ll j = pi[i-1];
		while(j>0 && s[j] != s[i])
			j = pi[j-1];
		if(s[i] == s[j])
		j++;
		pi[i] = j;
	}
	return pi;
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n,0);
	for(auto &i : ar)
		cin >> i;
	string pat,text="";
	cin >> pat;
	for(ll i=1;i<n;i++){
		if(ar[i]>ar[i-1])
		text += "G";
		else if(ar[i]<ar[i-1])
		text += "L";
		else
		text += "E";
	}
	vector<ll> pi = calculate_pi(pat);
	ll itr = 0;
	bool ans=0;
	for(ll i=0;text[i];i++){
		if(text[i] == pat[itr])
		itr++;
		else{
			ll j = pi[max(itr-1,0ll)];
			while(j>0 && text[i] != pat[j]){
				j = pi[j-1];
			}
			if(text[i] == pat[j])
			j++;
			itr = j;
		}
		// find if we reached the end
		if(itr == sz(pat)){
			itr = pi[itr-1];
			ans = 1;
		}
	}
	if(ans)
	cout << "YES";
	else
	cout << "NO";
	cout << "\n";
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


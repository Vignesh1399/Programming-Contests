#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	map<ll,ll> m;
	bool yes=1;
	vector<ll> ar(n+1,0);
	set<ll> s1;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		if(s1.find(ar[i]) != s1.end() && ar[i-1] == ar[i]){
			
		}
		else if(s1.find(ar[i]) == s1.end()){
			
		}
		else
		yes=0;
		s1.insert(ar[i]);
		m[ar[i]]++;
	}
	set<ll> s;
	for(ll i=1;i<=1e3;i++){
		if(m[i]==0) continue;
		if(s.find(m[i]) != s.end())
		yes=0;
		s.insert(m[i]);
	}
	if(yes)
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


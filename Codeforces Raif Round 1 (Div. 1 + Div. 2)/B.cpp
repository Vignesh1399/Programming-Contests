#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	string s;
	cin >> n ;
	cin >> s;
	// clock cycle
	ll val = -1;
	vector<ll> block(n+1,0);
	for(ll i=0;i<n;i++){
		if(s[i] == '<')
		break;
		val = (i+1)%n;
	}
	if(val == 0){
		cout << n <<"\n";
		return ;
	}
	for(ll i=n-1;i>=0;i--){
		if(s[i] == '>')
		break;
		val = (i+n)%n;
	}
	if(val == 0){
		cout << n <<"\n";
		return ;
	}
	else{
		for(ll i=0;i<n;i++){
			if(s[i] == '-')
				block[i] = block[(i+1)%n] = 1;
		}
		val = 0;
		for(ll i=0;i<n;i++){
			if(block[i]) 
				val++;
		}
		cout << val << "\n";
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


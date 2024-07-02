#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n),ngr(n);
	for(auto &i : ar)
	cin >> i;
	stack<ll> s;
	for(ll i=n-1;i>=0;i--){
		if(s.empty()){
			s.push(i);
			ngr[i] = -1;
		}
		else if(ar[s.top()]>ar[i]){
			ngr[i] = ar[s.top()];
			s.push(i);
		}
		else{
			while(!s.empty() && ar[s.top()]<=ar[i]){
				s.pop();
			}
			if(s.empty())
			ngr[i] = -1;
			else
			ngr[i] = ar[s.top()];
			s.push(i);
		}
	}
	for(auto i : ngr){
		cout << i << " ";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


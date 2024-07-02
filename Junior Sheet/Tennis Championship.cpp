#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	// f(n) : minimum number of players needed for winnner to play n matches
	ll matches = 0,players;
	queue<ll> q;
	q.push(2); // f(1)
	players = 2;
	matches = 1;
	q.push(3); // f(2)
	if(n>=3){
		players = 3;
		matches = 2;
	}
	while(players <= n){
		ll f = q.front();
		q.pop();
		ll s = q.front();
		q.push(s+f);
		//cout << s + f << " ";
		if(s+f<=n)
		matches++;
		players = s + f;
	}
	cout << matches;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


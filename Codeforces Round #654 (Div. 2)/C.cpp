#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b,n,m;
	cin >> a >> b >> n >> m;
	ll x = max(a,b), y = min(a,b);
	ll t1 = x;
	ll t2 = y;
	if(m<=t2)
	t2-=m;
	else{
		cout << "no\n";
		return ;
	}
	t1 += t2;
	if(n<=t1)
	cout << "yes";
	else
	cout << "no";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


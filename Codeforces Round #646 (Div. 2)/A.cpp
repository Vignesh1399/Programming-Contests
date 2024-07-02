#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,a;
	cin >> n >> x;
	ll o,e;
	o = e =0;
	for(ll i=0;i<n;i++){
		cin >> a;
		if(a%2) o++;
		else e++;
	}
	o = o - !(o%2);
	o = max(o,0ll);
	if(o==0)
	cout << "NO";
	else if(e==0 && x%2==1)
	cout << "YES";
	else if(e>0 && o>0 && x<=o+e)
	cout << "YES";
	else
	cout <<"no";
	cout <<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


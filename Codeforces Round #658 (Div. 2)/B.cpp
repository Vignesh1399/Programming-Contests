#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	ll cur = 1,k=0;
	for(auto &i : ar)
	cin >> i;
	for(ll i=0;i<n;i++){
		if(ar[i]>1){
			break;
		}
		cur++;
		cur%=2;
		k++;
	}
	if(k==n)
	cur = (cur+1)%2;
	//cout << cur << "\n";
	if(cur>0)
	cout <<"First\n";
	else
	cout <<"Second\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


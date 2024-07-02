#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void msort(vector<ll> &ar,ll s, ll e, vector<ll> &c){
	if(s == e)
	return ;
	ll mid = (s+e)/2;
	msort(ar,s,mid,c);
	msort(ar,mid+1,e,c);
	ll i = s,j = mid+1,k = 0;
	while(i<=mid && j<=e){
		if(ar[i]<ar[j])
		c[k++] = ar[i++];
		else
		c[k++] = ar[j++];
	}
	while(i<=mid)
		c[k++] = ar[i++];
	while(j<=e)
		c[k++] = ar[j++];
	k = 0;
	for(ll i=s;i<=e;i++){
		ar[i] = c[k++];
		cout << ar[i] << " ";
	}
	cout << "\n";
	
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n),c(n);
	for(auto &i : ar)
	cin >> i;
	msort(ar,0,n-1,c);
	for(auto i : ar)
	cout << i << " ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


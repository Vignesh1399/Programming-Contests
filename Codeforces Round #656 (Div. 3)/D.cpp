#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll cnt(string &s,ll start, ll end, char c){
	if(start == end)
	return (s[start] != c);
	ll mid = (end+start)/2;
	ll l = 0, r = 0;
	for(ll i=start;i<=mid;i++)
	if(s[i] != c)
	l++;
	for(ll i=mid+1;i<=end;i++)
	if(s[i] != c)
	r++;
	ll cntl = l + cnt(s,mid+1,end,c+1);
	ll cntr = r + cnt(s,start,mid,c+1);
	return min(cntl,cntr); 
}
void solve(){
	ll n;
	string s;
	cin >> n;
	cin >> s;
	ll ans = cnt(s,0,n-1,'a');
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


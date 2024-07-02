#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

char find_another(char a, char b){
	for(char c = 'a';c<='z';c++){
		if(c!=a && c!=b)
		return c;
	}
}

void solve(){
	ll n,t;
	string a,b;
	cin >> n >> t;
	cin >> a >> b;
	vector<char> out;
	vector<ll> same,diff;
	for(ll i=0;a[i];i++){
		out.pb(find_another(a[i],b[i]));
		if(a[i] == b[i])
		same.pb(i);
		else
		diff.pb(i);
	}
	while(t<n){
		if(sz(same)>=1){
			ll x = same.back();
			same.pop_back();
			out[x] = a[x];
			++t;
		}
		else if(sz(diff)>=2){
			ll x = diff.back();
			diff.pop_back();
			ll y = diff.back();
			diff.pop_back();
			out[x] = a[x];
			out[y] = b[y];
			++t;
		}
		else{
			cout << -1;
			return ;
		}
	}
	for(auto i : out)
	cout << i;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


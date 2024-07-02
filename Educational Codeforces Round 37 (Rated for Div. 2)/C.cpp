#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define first F
#define second S
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n);
	for(auto &i : ar)
	cin >> i;
	string s;
	cin >> s;
	ll cur = 0,prev=-1;
	for(ll i=0;s[i];i++){
		if(prev == -1 && s[i] == '1')
		prev = i;
		if(s[i] == '1'){
			cur++;
		}
		else{
			sort(ar.begin()+prev,ar.begin()+prev+cur+1);
			prev = -1;
			cur = 0;
		}
	}
	if(cur != 0)
	sort(ar.begin()+prev,ar.begin()+prev+cur+1);
	bool flag = 1;	
	for(ll i=0;i<n;i++){
		if(ar[i] != i+1)
		flag = 0;
	}
	if(flag)
	cout << "YES";
	else
	cout << "NO";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


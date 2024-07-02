#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define int long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,flag=0;
	cin >> n ;
	vector<ll> ar(n,0),pos(n+1,0),occ(n+2,1);
	for(ll i=1;i<=n;i++){
		cin >> ar[i-1];
		pos[ar[i-1]] = i;
		occ[i] = 0;
	}
	ll choice = -1;
	for(ll i=1;i<=n;i++){
		if(choice == -1)
		choice = pos[i]+1;
		else if(pos[i] == choice)
		choice = pos[i] + 1;
		else if(pos[i] != choice){
			flag=1;
			break;
		}
		occ[pos[i]] = 1;
		if(occ[choice])
		choice = -1;
		//cout<<choice<<" ";
	}
	
	if(flag)
	cout<<"no";
	else
	cout<<"yes";
	cout<<"\n";
}

int32_t main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


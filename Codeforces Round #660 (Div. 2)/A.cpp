#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	if(n<31 ){
		cout << "NO\n";
		return ;
	}
	else{
		if(n-30 == 10){
			cout << "YES\n";
			cout << 5 << " " << 15 << " " << 14 << " " << 6 << "\n";
		}
		else if(n-30 == 14){
			cout << "YES\n";
			cout << 13 << " " << 15 << " " << 10 << " " << 6 << "\n";
		}
		else if(n-30 == 6){
			cout << "YES\n";
			cout << 6 << " " << 15 << " " << 10 << " " << 5 << "\n";
		}
		else{
			cout << "YES\n";
			cout << 6 << " " << 10 << " " << 14 << " " << n-30 << "\n";
		}
		
	}
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


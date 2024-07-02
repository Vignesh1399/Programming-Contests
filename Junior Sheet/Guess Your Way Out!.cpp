#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> power(51,1);
void preprocess(){
	for(ll i=1;i<=50;i++)
		power[i] = power[i-1] * 2;
}

void solve(){
	ll h,n;
	preprocess();
	cin >> h >> n;
	ll th = h;
	ll lb = 0, ub = power[h];
	string dir = "";
	while(th--){
		ll mid = (lb+ub)/2;
		if(mid>=n){
			ub = mid;
			dir += "L";
		}
		else {
			lb = mid + 1;
			dir += "R";
		}
		//cout << lb << " " << ub <<"\n";
	}
	//cout << dir << "\n";
	ll ans = 0;
	char turn = 'L';
	for(ll i=0;dir[i];i++){
		if(dir[i] == turn)
		++ans;
		else
		ans += power[h];
		h--;
		turn = dir[i];
		turn = ((turn == 'L') ? 'R' : 'L');
	}
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll di[] = {1,-1,1,-1};
ll dj[] = {1,-1,-1,1};
vector<string> ans;

void printboard(vector<vector<bool>> &b){
	//cout << " "<< sol++ << "      " ;
	//cout << " #      1 2 3 4 5 6 7 8\n" << endl;
	string s="";
	for(ll j=1;j<=8;j++){
		for(ll i=1;i<=8;i++){
			if(b[i][j]){
				s += '0' + i;
				break;
			}
		}
	}
	ans.pb(s);
	//cout << "\n";
}

bool safe(ll i, ll j, vector<vector<bool>> &b){
	bool flag = 1;
	for(ll r=1;r<i;r++)
	if(b[r][j])
	flag = 0;
	for(ll k=0;k<4;k++){
		for(ll r=i+di[k],c=j+dj[k];r<=8 && c<=8 && r && c; r+=di[k],c+=dj[k])
		if(b[r][c])
		flag = 0;
	}
	return flag;	
}
void place(ll i, ll x, vector<vector<bool>> &b){
	if(i==9){
		printboard(b);
		return ;
	}
	if(i == x){
		place(i+1,x,b);
		return ;
	}
	for(ll j=1;j<=8;j++){
		if(safe(i,j,b)){
			b[i][j] = 1;
			place(i+1,x,b);
		}
		b[i][j] = 0;
	}
}

void solve(){
	ll x,y;
	cout << setw(2)<< setfill(' ') << setiosflags(ios::right);
	cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8\n" << endl;
	vector<vector<bool>> b(9,vector<bool>(9,0));
	cin >> x >> y;
	b[x][y] = 1;
	place(1,x,b);
	sort(ans.begin(),ans.end());
	for(ll i=0;i<sz(ans);i++){
		cout << " "<< i+1 << "      " ;
		for(ll j=0;ans[i][j];j++)
		cout << ans[i][j] << " ";
		cout << "\n";
	}
	ans.clear();
	//cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


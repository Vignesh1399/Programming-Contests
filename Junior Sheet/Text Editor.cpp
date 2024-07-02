#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
int d[105][100002];

void solve(){
	int n,r1,c1,r2,c2;
	cin >> n;
	vector<int> ar(n+1,0);
	for(ll i=1;i<=n;i++)
	cin >> ar[i];
	cin >> r1 >> c1 >> r2 >> c2;
	queue<pair<int,int>> q;
	d[r1][c1] = 1;
	q.push({r1, c1});
	while(!q.empty()){
		int r = q.front().first, c = q.front().second;
		q.pop();
		// right
		int newr = r, newc = min(c+1,ar[r]+1);
		if(!d[newr][newc]){
			d[newr][newc] = d[r][c] + 1;
			q.push({newr,newc});
		}
		//left
		newc = max(1,c-1);
		if(!d[newr][newc]){
			d[newr][newc] = d[r][c] + 1;
			q.push({newr,newc});
		}
		//up
		newr = max(1,r-1); newc = min(ar[newr]+1,c);
		if(!d[newr][newc]){
			d[newr][newc] = d[r][c] + 1;
			q.push({newr,newc});
		}
		//down
		newr = min(n,r+1); newc = min(ar[newr]+1,c);
		if(!d[newr][newc]){
			d[newr][newc] = d[r][c] + 1;
			q.push({newr,newc});
		} 
	}
	cout<<d[r2][c2] - 1<<"\n";
}

int main() {
    FAST;
    ll t=1;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //cin>>t;
    while(t--) solve();	
    return 0;
}


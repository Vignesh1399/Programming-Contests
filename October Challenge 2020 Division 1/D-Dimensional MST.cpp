#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int m[32][200000];
bool occ[200000];
struct point{
	int v[5] = {0,0,0,0,0};
};

inline void solve(){
	int node_cnt = 2,node=-1,n,d;
	scanf("%d%d",&n,&d);
	const int total = (1<<d);
	long long ans = 0;
	//set<pair<int,int>> s[total];
	deque<pair<int,int>> s[total];
	int mval=0;
	int cof[32][5];
	pair<int,int> curar[32];
	pair<int,int> mnode;
	vector<struct point> ar;
	// Getting Input -- n*d
	for(int i=0;i<n;++i){
		struct point p;
		for(int j=0;j<d;++j)
		scanf("%d",&p.v[j]);
		ar.emplace_back(p);
	}
	if(n == 1){
		cout << 0 << "\n";
		return ;
	}
	// Building Coefficient -- 2^k * k
	for(int i=0;i<total;++i){
		int temp = i;
		for(int j=0;j<d;++j){
			if(temp&1)
			cof[i][j] = -1;
			else
			cof[i][j] = 1;
			temp >>= 1;
		}
	}
	// Storing into Data Structures -- 2^k*n*(k+logn)
	for(int i=0;i<total;++i){
		for(int j=0;j<n;++j){
			int cur = 0;
			for(int x=0;x<d;x++)
				cur += cof[i][x] * ar[j].v[x];
			s[i].push_back({cur,j});
			m[i][j] = cur;
		}
	}
	for(int i=0;i<total;++i){
		sort(s[i].begin(),s[i].end());
	}
	for(int i=0;i<total;++i){
		auto ite = s[i].back();
		auto itb = s[i].front();
		if(ite.first - itb.first>=mval){
			mval = ite.first - itb.first;
			mnode = {ite.second,itb.second};
		}
	}
	for(int i=0;i<total;++i){
		pair<int,int> val = {m[i][mnode.first],m[i][mnode.second]};
		occ[mnode.first] = 1;
		occ[mnode.second] = 1;
		while(!s[i].empty() && occ[s[i].back().second])
		s[i].pop_back();
		while(!s[i].empty() && occ[s[i].front().second])
		s[i].pop_front();
		int a = val.first, b = val.second;
		curar[i] = {max(a,b),min(a,b)};
	}
	ans += mval;
	while(node_cnt<n){
		mval = 0;
		//node = -1;
		for(int i=0;i<total;++i){
			auto ite = s[i].back();
			auto itb = s[i].front();
			if(ite.first - curar[i].second>=mval){
				mval = ite.first - curar[i].second;
				node = ite.second;
			}
			if(curar[i].first - itb.first>=mval){
				mval = curar[i].first - itb.first;
				node = itb.second;
			}
		}
		for(int i=0;i<total;++i){
			occ[node] = 1;
			while(!s[i].empty() && occ[s[i].back().second])
			s[i].pop_back();
			while(!s[i].empty() && occ[s[i].front().second])
			s[i].pop_front();
			curar[i] = {max(curar[i].first,m[i][node]),min(curar[i].second,m[i][node])};
		}
		ans += mval;
		++node_cnt;
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
    solve();	
    return 0;
}


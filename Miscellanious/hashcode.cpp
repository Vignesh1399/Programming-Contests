#include <bits/stdc++.h>
#include<ctime>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) signed(a.size())
using namespace std;
vector<ll> score(1e5+1,0);
multiset<ll> s,s1; 
set<ll> lib_toprint;
struct Library{
	ll num_books; // num of books
	ll sign_time; //sign up time
	ll booksperday; // books per day
	vector<ll> id; // id of the books
	ll libid;
	long double val;
};
bool compinside(ll l1, ll l2){
	return score[l1]>score[l2];
}

bool comp(struct Library l1,struct Library l2){
	return l1.val>l2.val;
}

void solve(){
    ll B,L,D,tid;
    cin>>B>>L>>D;
    for(ll i=0;i<B;i++)
    cin>>score[i];
    vector<struct Library> lib(L);
    for(ll i=0;i<L;i++){
    	ll sum_scores=0;
    	cin>>lib[i].num_books>>lib[i].sign_time>>lib[i].booksperday;
    	//lib[i].sign_time*=(rand()%100)+1;
    	for(ll j=0;j<lib[i].num_books;j++){
    		cin>>tid;
    		lib[i].id.pb(tid);
    		sum_scores+=score[tid];
    	}
    	sum_scores*=(rand()%1000)+1;
    	lib[i].libid=i;
    	lib[i].val=(1.0*sum_scores*lib[i].booksperday)/(lib[i].sign_time*lib[i].sign_time);
    	sort(lib[i].id.begin(),lib[i].id.end(),compinside);
	}
	sort(lib.begin(),lib.end(),comp);
	ll A=L;
	//A=min(A,L);
	//cout<<A<<"\n";
	for(ll i=0;i<L;i++){
		ll nscan;
		nscan=lib[i].num_books;
		ll cur_books=0;
		for(ll j=0;j<nscan;j++){
			if(s.count(lib[i].id[j])==0){
				s.insert(lib[i].id[j]);
				++cur_books;
			}
		}
		//cout<<lib[i].libid<<" "<<cur_books<<"\n";
		if(cur_books)
		lib_toprint.insert(lib[i].libid);
	}
	cout<<lib_toprint.size()<<"\n";
	for(ll i=0;i<L;i++){
		set<ll> s3;
		if(lib_toprint.count(lib[i].libid)){
			ll nscan;
			nscan=lib[i].num_books;
			ll cur_books=0;
			for(ll j=0;j<nscan;j++){
				if(s1.count(lib[i].id[j])==0){
					//++cur_books;
					s1.insert(lib[i].id[j]);
					s3.insert(lib[i].id[j]);
				}
			}
			cout<<lib[i].libid<<" "<<s3.size()<<"\n";
			for(auto i:s3){
				cout<<i<<" ";
			}
			cout<<"\n";
		}
	}
}

int main() {
    
	freopen("d_inp.txt","r",stdin);
	freopen("d.txt","w",stdout);
	
    FAST;
    ll t=1,n,a,b,m;
    //cin>>t;
    while(t--) solve();	
    return 0;
}



#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

struct Node{
	bool end = 0;
	Node* next[3] = {NULL};
};
class Trie{
	public:
	Node* root;
	Trie(){
		root = new Node();
	}
	void insert(string s){
		Node* temp = root;
		for(ll i=0;s[i];i++){
			if(temp->next[s[i]-'a'] == NULL)
			temp->next[s[i]-'a'] = new Node();
			temp = temp->next[s[i]-'a'];
		}
		temp->end = 1;
	}
	bool search(Node* root, string &s, ll idx, ll flag){
		if(flag>1)
		return 0;
		Node* temp = root;
		if(idx == sz(s))
		return (flag==1ll && root->end);
		ll cf;
		bool ok = 0;
		for(ll i=0;i<3;i++){
			cf = flag;
			if(temp->next[i] == NULL)
			continue;
			if((s[idx]-'a') != i)
			cf++;
			ok = ok || search(temp->next[i],s,idx+1,cf);
		}
		return ok;
	}
};
void solve(){
	Trie t;
	ll n,m;
	cin >> n >> m;
	string s;
	for(ll i=0;i<n;i++){
		cin >> s;
		t.insert(s);
	}
	for(ll i=0;i<m;i++){
		cin >> s;
		bool ans = t.search(t.root,s,0,0);
		if(ans)
		cout << "YES\n";
		else
		cout << "NO\n";
	}
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}


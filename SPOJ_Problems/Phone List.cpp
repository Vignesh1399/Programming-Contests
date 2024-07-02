#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
/*
1. Initialize your data structure
2. Insert word into Trie
3. Search if word present in Trie 
4. Search if a prefix exists in Trie
*/
struct Node{
	bool isEnd = 0;
	Node* next[10] = {NULL};
};

class Trie{
	Node* root;
	public:
	Trie(){
		root = new Node();
	}
	bool search(string s){
		Node* temp = root;
		for(ll i=0;s[i];i++){
			if(temp->next[s[i]-'0'] == NULL)
			return 0;
			temp = temp->next[s[i]-'0'];
		}
		return temp->isEnd;
	}
	void insert(string s){
		Node* temp = root;
		bool ok = search(s);
		if(ok) return ;
		for(ll i=0;s[i];i++){
			if(temp->next[s[i]-'0'] == NULL)
				temp->next[s[i]-'0'] = new Node();
			temp = temp->next[s[i]-'0'];
		}
		temp->isEnd = 1;
	}
	bool isPrefix(string s){
		Node* temp = root;
		for(ll i=0;s[i];i++){
			if(temp->next[s[i]-'0'] == NULL)
			return temp->isEnd;
			temp = temp->next[s[i]-'0'];
		}
		return 1;
	}
};
void solve(){
	Trie t;
	ll n;
	cin >> n;
	string s[n];
	bool ok = 0;
	for(ll i=0;i<n;i++){
		cin >> s[i];
		ok = ok || t.isPrefix(s[i]);
		t.insert(s[i]);
	}
	if(ok)
	cout << "NO\n";
	else
	cout << "YES\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}


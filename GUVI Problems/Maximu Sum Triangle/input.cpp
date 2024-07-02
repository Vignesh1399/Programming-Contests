#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define cout out
#define cin in
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
using namespace std;

string to_string(int num, int dig) {
	string s = "";
	for (int i = 0; i < dig; i++) {
		s += ((num % 10) + '0');
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

ofstream out;

const int max_test_files = 5;


//test_specific contents
mt19937_64 rng(time(NULL));
// const ll maxn = 1e18;

//DSU
struct DSU {
	int N;
	vector<int> component, weight;

	DSU(int n) {
		N = n;
		component.resize(n + 1);
		weight.resize(n + 1);
		for (int i = 0; i <= N; i++) {
			component[i] = i;
			weight[i] = 1;
		}
	}

	int root(int x) {
		while (component[x] != x) {
			component[x] = component[component[x]];
			x = component[x];
		}
		return x;
	}

	void merge(int x, int y) {
		if (same(x, y))
			return;
		x = root(x);
		y = root(y);
		if (weight[x] < weight[y])
			swap(x, y);
		weight[x] += weight[y];
		component[y] = x;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}
};

//end of DSU
const int maxn = 1000;
const int maxm = 5;
const ll maxval = 1e9;
const int maxk = 1e9;
const int typeval = 2;

void generate() {
	int n = rand() % 10 + 1;
	out << n << "\n";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			ll num = rng() % maxval + 1;
			out << num << " ";
		}
		out << "\n";
	} 
	
	/*
	for(ll i=1;i<=n;i++){
		//for(ll j=1;j<=m;j++){
			ll c = rng() % maxval;
			cout << c <<" ";
		//}
		//cout << endl;
	}
	cout<<endl;
	*/
	/*
	for(ll i=1;i<=n;i++){
		ll ch = rng() % maxval + 1;
		cout<<ch<<" ";
	}
	out << endl;
	*/
	/*
	for (int i=1;i<=n;i++){
		ll len = rng() % 10 + 1;
		for(ll i=1;i<=len;i++){
			char ch = 'a'+ (rng()%26); 
			out << ch;
		}
		out << endl;
	}
	out << endl;
	out << m << endl;
	for (int i = 1; i <= m; i++) {
		ll val = rng() % maxval + 1; 
		out << val <<" ";
	}
	out << endl;
	DSU d(n);
	for (int i = 1; i < n; i++) {
		while (true) {
			int u = rng() % n + 1;
			int v = rng() % n + 1;
			if (d.same(u, v))
				continue;
			out << u << " " << v << endl;
			d.merge(u, v);
			break;
		}
	}
	*/
}

 void strong0() {
 	int n = rand() % 10 + 1;
 	n = maxn;
	out << n << "\n";
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			ll num = rng() % maxval + 1;
			out << num << " ";
		}
		out << "\n";
	} 
	
	/*
	for(ll i=1;i<=n;i++){
		//for(ll j=1;j<=m;j++){
			ll c = rng() % maxval;
			cout << c <<" ";
		//}
		//cout << endl;
	}
	cout<<endl;
	*/
	/*
	for(ll i=1;i<=n;i++){
		ll ch = rng() % maxval + 1;
		if(ch%2)
		ch++;
		cout<<ch<<" ";
	}
	out << endl;
	*/
	/*
	for(ll i=1;i<=n;i++){
		//for(ll j=1;j<=m;j++){
			//ll c = rng() % maxval;
			cout << i <<" ";
		//}
		//cout << endl;
	}
	cout<<endl;
	for(ll i=1;i<=n;i++){
		char ch = 'a' + rng() % maxval;
		cout<<ch;
	}
	out << endl;
	*/
 }

 void strong1() {
 	int n = rand() % maxn + 1;
	int m = rand() % (maxn) + 1;
	m = maxn;
	out << n << " " << m <<endl;
	for(ll i=1;i<=n;i++){
		ll c = rng() % maxval + 1;
		ll c1 = rng() % (maxval - c + 1);
		ll val = 1e9;
		ll ct = rng() % val + 1;
		cout << c <<" " << c + c1 << " " << ct << "\n";
		assert(c+c1<=1e5);
	}
	cout << endl;
 }	

 void strong2() {
 	vector<ll> inp;
	ll sum=0;
	int n = maxn;
	for (int i = 1; i <= n; i++) {
		ll val = rng() % maxval + 1; 
		inp.pb(val);
		sum += val;
	}
	ll a = sum - n + 1;
	ll aval = 5*n;
	assert(aval>=n && aval<=sum);
	out << n << " " << aval << endl;
	for(auto i :inp)
	out << i << " ";
	out << endl;
 }

//end of test_specific contents


int32_t main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input" + to_string(i, 2) + ".txt";
		out.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		if (i == 0)
			strong0();
		/*
		else if (i == 1)
		 	strong1();
		else if (i == 2)
			strong2();
		*/
		else
		generate();
		out.close();
		assert(!out.is_open());
	}
	return 0;
}
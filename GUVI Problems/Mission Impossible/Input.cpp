#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
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

const int max_test_files = 10;


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
const int maxn = 1e5;
const ll maxval = 1e9;
void generate() {
	int n = rand() % maxn + 1 ;
  vector<ll> inp;
	out << n << endl;
	for (int i = 1; i<=n; i++) {
    ll temp = rng() % maxval + 1;
		inp.pb(temp);
	} 
    for(auto i:inp)
    out << i << " ";
  
	out << endl;
  /*
	DSU d(n);
	for (int i = 1; i < n; i++) {
		while (true) {
			int u = rand() % n + 1;
			int v = rand() % n + 1;
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
  out << 1 << endl;
 	out << 0;
 }

 void strong1() {
 	out << 3 << endl;
  out << -2 << " " << 0 << " " << -1; 
 }

 void strong2() {
 	out << 4 << endl;
  out << 2 << " " << 3 <<" "<<-2 <<" "<< 4;
 }

 void strong3(){
  int n = 1e5;
  vector<ll> inp;
	out << n << endl;
	for (int i = 1;i <= n; i++) {
    ll temp = rng() % maxval + 1;
		inp.pb(temp);
	}
    for(auto i:inp)
    out << i << " ";
  
	out << endl;
 }

//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input" + to_string(i, 2) + ".txt";
		out.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		if (i == 3)
	 	strong3();
	 	/*
		 else if (i == 1)
		 	strong1();
		 else if (i == 2)
		 	strong2();
    else if(i == 3)
      strong3();
      */
		else
		generate();
		out.close();
		assert(!out.is_open());
	}
	return 0;
}
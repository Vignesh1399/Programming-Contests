#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

class DivideLoot {
  public:
  string verify(int N, vector <int> loot) {
      map<int,int> m;
      int sum = 0;
      for(int i=0;i<sz(loot);i++){
      	sum += loot[i];
      	m[loot[i]]++;
  	}
  	int each = 0;
  	bool flag = 1;
  	if(sum % N != 0)
  	flag = 0;
  	else
  	each = sum/N;
  	for(int i=0;i<sz(loot);i++){
  		if(m[loot[i]]<=0) continue;
  		else{
  			m[loot[i]]--;
  			if(each - loot[i] > 0)
  			m[each-loot[i]]--;
  			else if(each - loot[i] < 0)
  			flag = 0;
  		}
  		if(m[each-loot[i]] < 0)
  		flag = 0;
  	}
  	string ans;
  	if(flag) ans = "possible";
  	else ans = "impossible";
  	return ans;
  }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 1;
			int loot[]                = {47};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int loot[]                = {10, 8, 10, 1, 1};
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int loot[]                = {3, 9, 10, 7, 1};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 6;
			int loot[]                = {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
			string expected__         = "possible";

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 2;
			int loot[]                = {40, 1, 42};
			string expected__         = "impossible";

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int loot[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int loot[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int loot[]                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DivideLoot().verify(N, vector <int>(loot, loot + (sizeof loot / sizeof loot[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

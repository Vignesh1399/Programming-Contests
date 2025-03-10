#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

class AtLeastKDays {
  public:
  long long sumOfMinCosts(vector <string> costs, int minDays) {
      
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string costs[]            = {"-12",
 "3-6",
 "45-"};
			int minDays               = 1;
			long long expected__      = 34;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string costs[]            = {"-111111111",
 "1-11111111",
 "11-1111111",
 "111-111111",
 "1111-11111",
 "11111-1111",
 "111111-111",
 "1111111-11",
 "11111111-1",
 "111111111-"};
			int minDays               = 1000000000;
			long long expected__      = 100000000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string costs[]            = {"-12",
 "3-6",
 "45-"};
			int minDays               = 6;
			long long expected__      = 122;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string costs[]            = ;
			int minDays               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string costs[]            = ;
			int minDays               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string costs[]            = ;
			int minDays               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = AtLeastKDays().sumOfMinCosts(vector <string>(costs, costs + (sizeof costs / sizeof costs[0])), minDays);
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

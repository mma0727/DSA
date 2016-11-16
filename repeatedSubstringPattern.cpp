#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Solution {
private:
	bool _repeatedSubstringWithLength(const std::string& str, int len) {
		std::string pattern = str.substr(0, len);
		for (int i = len; i < int(str.size()); i+= len) {
			if (pattern != str.substr(i, len))
				return false;
		}
		return true;
	}
public:
	bool repeatedSubstringPattern(std::string str) {
		int n = int(str.size());
		if (n < 2) return false;

		int d = 1;
		while (d*d <= n) {
			if (n%d == 0) {
				if (_repeatedSubstringWithLength(str, d)) return true;
				if (d > 1)
					if (_repeatedSubstringWithLength(str, n/d)) return true;
			}
			++d;
		}
		return false;
	}
};

int main() {
	Solution sol;
	std::vector<std::string> test{"abcabc", "aaa", "a", "abcd"};
	for (auto& s: test) {
		if (sol.repeatedSubstringPattern(s)) {
			std::cout << std::setw(16) << "[repeated]: " << s << std::endl;
		}else {
			std::cout << std::setw(16) << "[non-repeated]: " << s << std::endl;
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestPalindromicSubsequence(const std::string& s) {
    int n = s.length();
    std::vector<std::vector<std::string>> dp(n, std::vector<std::string>(n, ""));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = s[i];
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                dp[i][j] = s[i] + dp[i + 1][j - 1] + s[j];
            } else {
                if (dp[i + 1][j].length() > dp[i][j - 1].length()) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    std::string s;
    std::cin >> s;
    std::string longestPalindrome = longestPalindromicSubsequence(s);
    std::cout << longestPalindrome.size() << '\n';
    std::cout << longestPalindrome;
    return 0;
}

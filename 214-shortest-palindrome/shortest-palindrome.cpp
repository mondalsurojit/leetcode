class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int n = s.length();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string fs = s + "#" + rev_s;
        int m = fs.length();
        vector<int> lps(m, 0);
        int pre = 0, suf = 1;
        while (suf < m) {
            if (fs[pre] == fs[suf]) {
                lps[suf] = pre + 1;
                pre++, suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        string np = rev_s.substr(0, n - lps[m - 1]);
        return np + s;
    };
};
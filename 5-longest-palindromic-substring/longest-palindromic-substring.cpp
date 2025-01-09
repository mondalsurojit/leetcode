class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string fs = s + '#' + rev_s;
        int fs_n = fs.length();

        string fs_copy = fs;
        vector<int> final_lps(n + 1, 0);
        int lpds = final_lps[0], lpdi = 0;

        if (n == 0)
            return "";

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                fs_copy.erase(0, 1);
                fs_copy.erase(fs_copy.size() - 1, 1);
                fs_n = fs_copy.size();
            }
            vector<int> lps(fs_n, 0);
            int pre = 0, suf = 1;
            while (suf < fs_n) {
                if (fs_copy[pre] == fs_copy[suf]) {
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
            final_lps[i] = lps.back();
            if (final_lps[i] > lpds) {
                lpds = final_lps[i];
                lpdi = i;
            }
        }
        return s.substr(lpdi, lpds);
    }
};
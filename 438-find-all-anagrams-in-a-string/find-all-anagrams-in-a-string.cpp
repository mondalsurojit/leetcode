class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        int n = s.length(), m = t.length(), oll = n - m + 1;
        if (m > n)
            return {};

        vector<int> alp_arr(26, 0);
        vector<int> anagram_arr;

        for (int k = 0; k < m; k++) {
            int pos = t[k] - 'a';
            alp_arr[pos]++;
        }

        for (int i = 0; i < oll; i++) {
            vector<int> alp_arr_copy = alp_arr;
            bool flag = true;
            for (int j = i; j < i + m; j++) {
                int pos = s[j] - 'a';
                alp_arr_copy[pos]--;
            }
            for (int j = i; j < i + m; j++) {
                int pos = s[j] - 'a';
                 if (alp_arr_copy[pos] != 0) {
                    flag = false;
                }
            }
            if (flag == true) {
                anagram_arr.push_back(i);
            }
        }
        return anagram_arr;
    }
};
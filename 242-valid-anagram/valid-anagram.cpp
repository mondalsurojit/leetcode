class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        bool flag;
        vector<int> arr(26, 0);
        if (n != m) {
            return false;
        } else {
            for (int i = 0; i < n; i++) {
                arr[s[i] - 'a'] = arr[s[i] - 'a'] + 1;
                arr[t[i] - 'a'] = arr[t[i] - 'a'] - 1;
            }
            for (int j = 0; j < 26; j++) {
                if (arr[j] != 0) {
                    flag = false;
                    break;
                } else {
                    flag = true;
                }
            }
        }
        return flag;
    }
};
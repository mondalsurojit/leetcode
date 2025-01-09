class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> arr(26, 0);
        if (n != m) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int j = 0; j < 26; j++) {
            if (arr[j] != 0)
                return false;
        }
        return true;
    }
};
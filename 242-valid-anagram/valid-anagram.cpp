class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        string temp = t;
        bool found;
        if (n != m) {
            return false;
        } else {
            vector<string> arr(n, "");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < temp.length(); j++) {
                    if (s[i] == temp[j]) {
                        arr[i] = t[j];
                        temp.erase(j, 1);
                        found = true;
                        break;
                    }
                }
                if (!found)
                    return false;
            }
        }
        return (temp.empty());
    }
};
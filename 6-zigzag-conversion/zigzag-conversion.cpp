class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.length();
        int i, j = 0, k = 0, count = 0;
        vector<vector<char>> arr(numRows, vector<char>(s.length(), '\0'));
        if (numRows == 1) return s;
        while (k < l) {
            if (count % 2 == 0) {
                for (i = 0; i < numRows && k < l; i++) {
                    arr[i][j] = s[k];
                    k++;
                }
                j++;
            } else {
                for (i = numRows - 2; i > 0 && k < l; i--) {
                    arr[i][j] = s[k];
                    k++;
                    j++;
                }
            }
            count++;
        }

        string rowString = "";
        for (int m = 0; m < numRows; m++) {
            for (int n = 0; n < j; n++) {
                if (arr[m][n] != '\0') {
                    rowString += arr[m][n];
                }
            }
        }
        return rowString;
    }
};
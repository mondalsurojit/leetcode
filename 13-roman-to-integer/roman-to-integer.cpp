class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int total = 0;
        for (int i = 0; i < n; i++) {
            char k = s[i];
            char l = s[i + 1];
            int kVal = charVal(k);
            int lVal = charVal(l);
            if (kVal < lVal) {
                if (k == 'I' && l == 'V') {
                    total += 4;
                    i++;
                } else if (k == 'I' && l == 'X') {
                    total += 9;
                    i++;
                } else if (k == 'X' && l == 'L') {
                    total += 40;
                    i++;
                } else if (k == 'X' && l == 'C') {
                    total += 90;
                    i++;
                } else if (k == 'C' && l == 'D') {
                    total += 400;
                    i++;
                } else if (k == 'C' && l == 'M') {
                    total += 900;
                    i++;
                }
            } else {
                total = total + kVal;
            }
        }
        return total;
    }

    int charVal(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};
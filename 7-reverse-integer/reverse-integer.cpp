class Solution {
public:
    int reverse(int x) {
        long long rx = 0;
        while (x != 0) {
            int rem = x % 10;
            x = x / 10;
            rx = rx * 10 + rem;
            if (rx > INT_MAX || rx < INT_MIN)
                return 0;
        }
        return (int)rx;
    }
};

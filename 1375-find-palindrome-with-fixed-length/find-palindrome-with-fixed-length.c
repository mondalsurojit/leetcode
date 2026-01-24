/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* kthPalindrome(int* queries, int queriesSize, int intLength,
                         int* returnSize) {
    long long* arr = malloc(queriesSize * sizeof(long long));
    int n = (intLength + 1) / 2, smallest, largest, digit;
    long long quo, rem, final;
    if (n == 1) {
        smallest = 1, largest = 9;
    } else {
        smallest = 1, largest = 9;
        for (int i = 1; i < n; i++) {
            smallest *= 10;
            largest = largest * 10 + 9;
        }
    }
    int count = largest - smallest + 1;
    for (int k = 0; k < queriesSize; k++) {
        if (queries[k] > count) {
            arr[k] = -1;
        } else {
            int halfPal = queries[k] + smallest - 1;
            quo = halfPal, final = halfPal, digit = intLength;
            while (quo > 0) {
                if (intLength % 2 == 1 && digit == intLength) {
                    quo /= 10;
                } else {
                    rem = quo % 10;
                    quo /= 10;
                    final = final * 10 + rem;
                }
                digit--;
            }
            arr[k] = final;
        }
    }
    *returnSize = queriesSize;

    return arr;
}

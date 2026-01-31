bool isPalindrome(char* s) {
    int l = strlen(s), front = 0, rear = l - 1;
    while (rear >= front) {
        if (!isalnum(s[front]))
            front++;
        else if (!isalnum(s[rear]))
            rear--;
        else if (tolower(s[front]) == tolower(s[rear])) {
            front++, rear--;
        } else
            return 0;
    }
    return 1;
}
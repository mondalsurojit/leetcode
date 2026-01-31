/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *ptr1 = head, *ptr2 = head;
    int m = 1, n;
    if (head == NULL)
        return 0;
    while (ptr1->next != NULL) {
        ptr1 = ptr1->next;
        m++;
    }
    if (k != 0)
        n = m - (k % m);
    ptr1->next = head;
    while (n > 0) {
        ptr1 = ptr1->next;
        n--;
    }
    head = ptr1->next;
    ptr1->next = NULL;
    return head;
}
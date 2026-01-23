/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow, *fast, *prev, *current, *temp, *left, *right;

    if (head == NULL || head->next == NULL) return true;
    slow = fast = left = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    prev = NULL;
    current = slow;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    right = prev;
    while (right != NULL) {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return 1;
}
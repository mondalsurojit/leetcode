/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(struct ListNode* lastNodeAddress) {
    struct ListNode* temp = NULL;
    if (lastNodeAddress == NULL) {
        temp = malloc(sizeof(struct ListNode));
        temp->next = NULL;
    } else if (lastNodeAddress->next == NULL) {
        temp = malloc(sizeof(struct ListNode));
        lastNodeAddress->next = temp;
        temp->next = NULL;
    }
    return temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l1ptr = l1, *l2ptr = l2;
    struct ListNode* l3head = newNode(NULL);
    struct ListNode* l3ptr = l3head;
    int carry = 0;
    while (l1ptr != NULL || l2ptr != NULL) {
        int val1 = (l1ptr != NULL) ? l1ptr->val : 0;
        int val2 = (l2ptr != NULL) ? l2ptr->val : 0;
        l3ptr->val = carry + val1 + val2;
        carry = 0;
        if (l3ptr->val >= 10) {
            l3ptr->val = l3ptr->val - 10;
            carry = 1;
        }
        if (l1ptr != NULL)
            l1ptr = l1ptr->next;
        if (l2ptr != NULL)
            l2ptr = l2ptr->next;
        if(l1ptr != NULL || l2ptr != NULL)
            l3ptr = newNode(l3ptr);
    }
    if (carry == 1) {
        l3ptr = newNode(l3ptr);
        l3ptr->val = 1;
    }
    return l3head;
}
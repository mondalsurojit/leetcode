/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNode(struct ListNode* lastNodeAddress) {
    struct ListNode *head, *newNodeAddress;
    if (lastNodeAddress == NULL) {
        head = malloc(sizeof(struct ListNode));
        head->next = NULL;
        return head;
    } else {
        newNodeAddress = malloc(sizeof(struct ListNode));
        lastNodeAddress->next = newNodeAddress;
        newNodeAddress->next = NULL;
    }
    return newNodeAddress;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *l1ptr = list1, *l2ptr = list2, *l3head = NULL,
                    *l3ptr = NULL;
    while (l1ptr != NULL || l2ptr != NULL) {
        if (l3ptr == NULL) {
            l3head = createNode(l3ptr);
            l3ptr = l3head;
        } else {
            l3ptr = createNode(l3ptr);
        }

        if (l1ptr == NULL) {
            l3ptr->val = l2ptr->val;
            l2ptr = l2ptr->next;
        } else if (l2ptr == NULL) {
            l3ptr->val = l1ptr->val;
            l1ptr = l1ptr->next;
        } else if (l1ptr->val >= l2ptr->val) {
            l3ptr->val = l2ptr->val;
            l2ptr = l2ptr->next;
        } else {
            l3ptr->val = l1ptr->val;
            l1ptr = l1ptr->next;
        }
    }
    return l3head;
}
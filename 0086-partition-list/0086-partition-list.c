/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode lessDummy, greaterDummy;
    struct ListNode *less = &lessDummy;
    struct ListNode *greater = &greaterDummy;

    less->next = NULL;
    greater->next = NULL;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    greater->next = NULL;          // End the greater list
    less->next = greaterDummy.next; // Connect both lists

    return lessDummy.next;
}
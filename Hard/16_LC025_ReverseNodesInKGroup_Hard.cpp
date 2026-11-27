class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrevious = &dummy;

        while (true) {

            // Find the kth node.
            ListNode* kth = groupPrevious;

            for (int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            if (kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            // Reverse the current group.
            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            while (current != groupNext) {

                ListNode* nextNode = current->next;

                current->next = previous;

                previous = current;
                current = nextNode;
            }

            // Connect the reversed group.
            ListNode* oldStart = groupPrevious->next;

            groupPrevious->next = kth;

            groupPrevious = oldStart;
        }

        return dummy.next;
    }
};

/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *tail = head, *prev = nullptr, *curr = head;

        for (int i = 0; i < n; ++i) {
            tail = tail->next;
        }

        while (tail != nullptr) {
            tail = tail->next;
            prev = curr;
            curr = curr->next;
        }

        // there is a memory leak!

        if (curr == head) {
            return head->next;
        }

        prev->next = curr->next;
        return head;
    }
};

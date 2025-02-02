/**
 * https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *tmp = new ListNode(), *prv, *fst, *snd;
        tmp->next = head;

        prv = tmp;
        fst = head;
        snd = (fst != nullptr) ? fst->next : nullptr;

        while (fst != nullptr && snd != nullptr) {
            prv->next = snd;
            fst->next = snd->next;
            snd->next = fst;

            prv = fst;
            fst = fst->next;
            if (fst != nullptr) {
                snd = fst->next;
            }
        }

        // with memory leak!

        return tmp->next;
    }
};

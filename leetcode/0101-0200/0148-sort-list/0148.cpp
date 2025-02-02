/**
 * https://leetcode.com/problems/sort-list/
 */

#include <iostream>

using namespace std;

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
    pair<ListNode *, ListNode *> mergeTwoLists(ListNode *segm_l, ListNode *segm_r, ListNode *outer)
    {
        ListNode *head = new ListNode(), *tail = head;
        ListNode *end_l = segm_r, *end_r = outer;

        // exhaust both segments

        while (segm_l != end_l || segm_r != end_r) {
            if (segm_r == end_r || (segm_l != end_l && segm_l->val < segm_r->val)) {
                tail->next = segm_l;
                segm_l = segm_l->next;
            }
            else {
                tail->next = segm_r;
                segm_r = segm_r->next;
            }
            tail = tail->next;
        }

        // fix tail termination

        tail->next = outer;

        auto head_result = head->next;
        auto tail_result = tail;
        delete head;

        return pair(head_result, tail_result);
    }

    ListNode *nextSegm(ListNode *segm, size_t segm_len)
    {
        for (size_t i = 0; i < segm_len; ++i) {
            segm = (segm == nullptr) ? nullptr : segm->next;
        }
        return segm;
    }

    ListNode *sortList(ListNode *list)
    {
        auto head = new ListNode();
        head->next = list;

        auto temp = list;
        size_t list_len = 0;

        // find out the entire length of the list

        while (temp != nullptr) {
            ++list_len;
            temp = temp->next;
        }

        size_t segm_len = 1;

        // merge segments in-place and increase segment length

        while (segm_len < list_len) {
            auto prev = head;

            auto segm_l = head->next;
            auto segm_r = nextSegm(segm_l, segm_len);
            auto segm_o = nextSegm(segm_r, segm_len);

            while (segm_l != nullptr && segm_r != nullptr) {
                auto [h, t] = mergeTwoLists(segm_l, segm_r, segm_o);

                prev->next = h;
                prev = t;

                segm_l = segm_o;
                segm_r = nextSegm(segm_l, segm_len);
                segm_o = nextSegm(segm_r, segm_len);
            }

            segm_len *= 2;
        }

        auto result = head->next;
        delete head;

        return result;
    }
};

int main()
{
    // auto a0 = new ListNode(5);
    // auto a1 = new ListNode(0);
    // auto a2 = new ListNode(3);
    // auto a3 = new ListNode(4);
    // auto a4 = new ListNode(1);

    // a0->next = a1;
    // a1->next = a2;
    // a2->next = a3;
    // a3->next = a4;

    auto a0 = new ListNode(1);
    auto a1 = new ListNode(2);
    auto a2 = new ListNode(3);
    auto a3 = new ListNode(4);

    a0->next = a1;
    a1->next = a2;
    a2->next = a3;

    Solution s;
    auto result = s.sortList(a0);

    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}

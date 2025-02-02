/**
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(-1), *tail = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }

        if (list2 != nullptr) {
            tail->next = list2;
        }

        auto result = head->next;
        delete head;

        return result;
    }
};

int main()
{
    auto a0 = new ListNode(1);
    auto a1 = new ListNode(4);
    auto a2 = new ListNode(5);

    a0->next = a1;
    a1->next = a2;

    auto b0 = new ListNode(1);
    auto b1 = new ListNode(3);
    auto b2 = new ListNode(4);

    b0->next = b1;
    b1->next = b2;

    Solution s;
    auto result = s.mergeTwoLists(a0, b0);

    cout << result->val << endl;

    return 0;
}

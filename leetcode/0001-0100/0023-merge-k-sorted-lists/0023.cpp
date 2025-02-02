/**
 * https://leetcode.com/problems/merge-k-sorted-lists/
 */

#include <iostream>
#include <queue>
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr, *tail = nullptr;

        auto cmp = [](pair<ListNode *, int> &l, pair<ListNode *, int> &r) { return l.first->val > r.first->val; };

        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, decltype(cmp)> queue(cmp);

        // initialize queue

        for (int i = 0; i < lists.size(); ++i) {
            auto element = lists[i];
            if (element != nullptr) {
                queue.push(pair(element, i));
                lists[i] = element->next;
            }
        }

        // extract min until empty

        while (!queue.empty()) {
            auto min = queue.top();
            queue.pop();

            if (head == nullptr || tail == nullptr) {
                head = min.first;
                tail = min.first;
            }
            else {
                tail->next = min.first;
                tail = tail->next;
            }

            auto list_item = lists[min.second];

            if (list_item != nullptr) {
                lists[min.second] = list_item->next;
                queue.push(pair(list_item, min.second));
            }
        }

        return head;
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

    auto c0 = new ListNode(2);
    auto c1 = new ListNode(6);

    c0->next = c1;

    Solution s;
    vector<ListNode *> v{a0, b0, c0};

    auto result = s.mergeKLists(v);

    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}

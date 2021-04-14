/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// https://leetcode.com/problems/merge-two-sorted-lists
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ;
        vector<int> ans;
        while (l1 != NULL and l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                ans.push_back(l1->val);
                l1 = l1->next;
            }
            else
            {
                ans.push_back(l2->val);
                l2 = l2->next;
            }
        }
        while (l1 != NULL)
        {
            ans.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            ans.push_back(l2->val);
            l2 = l2->next;
        }
        if (ans.size() == 0)
        {
            ListNode *nu;
            return nu;
        }

        ListNode *temp = new ListNode(ans[0]);
        ListNode *head = temp;
        for (int i = 1; i < ans.size(); i++)
        {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        return head;
    }
};
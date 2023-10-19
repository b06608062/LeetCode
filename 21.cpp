// 21. Merge Two Sorted Lists

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr)
      return list2;
    else if (list2 == nullptr)
      return list1;

    ListNode *head = new ListNode(0);
    ListNode *p = head;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        p->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        p->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      p = p->next;
    }
    if (list1 != nullptr)
      p->next = list1;
    else
      p->next = list2;

    return head->next;
  }
};
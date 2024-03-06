class Solution {
public:
  ListNode* mergeTwoList(ListNode* first, ListNode* second) {
    if (!first)
      return second;
    if (!second)
      return first;
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    while (first && second) {
      if (first->val < second->val) {
        temp->next = first;
        temp = temp->next;
        first = first->next;
      } else {
        temp->next = second;
        temp = temp->next;
        second = second->next;
      }
    }
    while (first) {
      temp->next = first;
      temp = temp->next;
      first = first->next;
    }
    while (second) {
      temp->next = second;
      temp = temp->next;
      second = second->next;
    }
    return ans->next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
      return NULL;
    }
    ListNode* head = lists[0];

    for (int i = 1; i < lists.size(); i++) {
      head = mergeTwoList(head, lists[i]);
    }

    return head;
  }
};
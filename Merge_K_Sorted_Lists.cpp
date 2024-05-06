#include<bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class Solution {
public:
  ListNode* mergeTwoList(ListNode* first, ListNode* second) {
    if (!first)
      return second;
    if (!second)
      return first;
    ListNode* answer = new ListNode(-1);
    ListNode* temp = answer;
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
    return answer->next;
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
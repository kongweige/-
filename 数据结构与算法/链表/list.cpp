#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

// 添加节点到链表尾部
void appendNode(ListNode* &head,int value)
{
  // 创建新节点
  ListNode* new_node = new ListNode(value);
  // 判断head是否为空
  if(head == nullptr) {
    head = new_node;
  }else {
    // 创建一个指向head的指针用于遍历链表 保证head在头部
    ListNode* temp = head;
    while(temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

// 输出链表
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// 反转链表
ListNode* reverseList(ListNode* head)
{
  ListNode* pre = nullptr; // 前置指针
  ListNode* cur = head; // 当前指针
  
  if(head == nullptr && head->next != nullptr) {
    return head;
  }else {
    while(cur) {
      // 创建一个指向当前节点下一个位置的指针、
      ListNode* next_node = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next_node;
    }
  }
  return pre;
}

// 两两交换节点
ListNode* swapPairs(ListNode* head)
{
  if(!head || !head->next)
    return head;
 
  ListNode* dummy_node = new ListNode(0);
  ListNode*pre = dummy_node;
  dummy_node->next = head;
  
  while (pre->next != nullptr && pre->next->next != nullptr){
    ListNode* temp = pre->next->next;
    pre->next->next = temp->next;
    temp->next = pre->next;
    pre->next = temp;

    pre = temp->next;
  }

  return dummy_node->next;
}

// 环形链表
bool hasCycle(ListNode *head) 
{
    if(!head)  
      return false;
    
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;

      if(fast->val == slow->val)
        return true;
    }
    return false;
}

int main()
{
 // 创建链表头节点
  ListNode* head = nullptr;

  // 构建链表 1 2 3 4 5
  for (int i = 1; i <= 5; ++i) {
    appendNode(head, i);
  } 
  // 输出链表
  std::cout << "Linked List: ";
  printList(head);


  // 反转链表
  ListNode*reverse_list = reverseList(head);
  // 输出链表
  std::cout << "Reverse List: ";
  printList(reverse_list);


  // 两两交换链表
  ListNode*swap_list = swapPairs(reverse_list);
  // 输出链表
  std::cout << "Swap List: ";
  printList(swap_list);

  // 环形链表
  bool b_cycle = hasCycle(swap_list);
  if(b_cycle)
    std::cout << "Cycle List: true " << b_cycle << std::endl;
  else
    std::cout << "Cycle List: false " << b_cycle << std::endl;
    
  delete reverse_list;
  delete swap_list;
  return 0;
}
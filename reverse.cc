#include <iostream>
#include <cassert>

struct LNode {
  int data_;
  LNode* next_;
};

//////////////////////////////////////////////////////////////////////////////
void print_list(const LNode* head)
{
  while (head) {
    std::cout << head->data_ << " ";
    head = head->next_;
  }
  std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////
// Reverse a list iteratively
LNode*
reverse_list(LNode* head)
{
	if(!head)		return head;
	if(!(head->next_)) 	return head;
	LNode* newHead = head->next;
	while(!(head->next_->next))
	{
		newHead = head->next_->next_;
		head->next_->next_ = head;

}

//////////////////////////////////////////////////////////////////////////////
// Reverse a list recursively
LNode*
reverse_list_r(LNode* head)
{	
	if(!head)		return head;
	if(!(head->next_))	return head;
	reverse_list_r(head)->next_ = head;
	return head;
}

////////////////////////////////////////////////////////////////////////////// 
int main()
{
...
}

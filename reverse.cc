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
	LNode* newHead = nullptr;
	LNode* prevHead = nullptr;
	while(head != nullptr)
	{
		newHead = head->next_;
		head->next_ = prevHead;
		prevHead = head;
		head = newHead;
	}
	return prevHead;
}

//////////////////////////////////////////////////////////////////////////////
// Reverse a list recursively
LNode*	reverse_list_r(LNode* head)
{
	if(!head) 	return head;
	if(!(head->next_))	return head;
	LNode* newHead = reverse_list_r(head->next_);
	head->next_->next_ = head;
	head->next_ = nullptr;
	return newHead;
}

void test(LNode* head)
{
	std::cout<<"original list:"<<"\n";
	print_list(head);
	std::cout<<"\n";
		
	std::cout<<"iterated list:"<<"\n";
	head = reverse_list(head);
	print_list(head);
	
	std::cout<<"\n";
	std::cout<<"recursively reversed list:"<<"\n";
	head = reverse_list_r(head);
	print_list(head);
	std::cout<<"\n"<<"\n";
}

////////////////////////////////////////////////////////////////////////////// 
int main()
{
	
	LNode* head = new LNode{0, nullptr};
	test(head);
	head = nullptr;
	test(head);	
	for (int listLen = 1; listLen < 5; listLen ++)
	{
		head =new LNode{ 0,new LNode{1, nullptr}};
		LNode* current = head->next_;
		for(int i = 2; i<=listLen ; i++)
		{
			current->next_ = new LNode{i,nullptr};
			current = current->next_;
		}
		test(head);
		}

}

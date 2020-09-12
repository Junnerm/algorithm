#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//环路检测
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int value)
	{
		this->val = value;
		this->next = NULL;
	}
};

ListNode* detectCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	if (fast != slow)
	{
		return NULL;
	}
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
ListNode* initList()
{
	ListNode* Node1 = new ListNode(1);
	ListNode* Node2 = new ListNode(2);
	ListNode* Node3 = new ListNode(3);
	ListNode* Node4 = new ListNode(4);
	ListNode* Node5 = new ListNode(5);
	ListNode* Node6 = new ListNode(6);
	ListNode* Node7 = new ListNode(7);
	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
	Node5->next = Node6;
	Node6->next = Node7;
	Node7->next = Node6;
	return Node1;
}
int main()
{
	ListNode* temp = initList();
	ListNode* res = detectCycle(temp);
	cout << "----------环路的头节点为：-----------" << endl;
	cout << res->val << endl;

	return 0;
}
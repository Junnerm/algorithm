#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	链表环路检测的功能实现主要有三部分组成，
	1、class ListNode
	2、ListNode* detectCycle(ListNode* head)
	3、ListNode* initList()
*/
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

/*
	寻找下一个排列的数字
	比如12354，就需要输出12435
	如果整体的数据是降序排列的则没有比起更大的排列
	否则就应该从后向前进行遍历，寻找第一个不满足升序排列的数字
	然后将该位置上的数据与遍历过的数字中比该数要大中的最小值进行互换位置
	最后将所有的遍历过的数据进行数值的反转。

*/
void nextPermutation(vector<int>& nums) {
	//（从前往后看）如果vector的值是一种降序的方式进行排列的，则如此的情况下是没有比它更大的数存在的，
	//如果想要得到比当前数字大的最小值，也就是下一个数的排列值
	//则就需要从后往前进行寻找第一个破坏升序的数字，将其与遍历过后的数值中比它大的最小值进行位置的交换
	//然后将遍历过的数据进行反转
	int len = nums.size();
	int flag = 0;
	for (int i = len - 2; i >= 0; i--)
	{
		if (nums[i] >= nums[i + 1])
		{
			continue;
		}
		int index = len - 1;
		int temp = -1;
		for (int j = len - 1; j > i; j--)
		{
			if (nums[j] > nums[i])
			{
				if (temp == -1)
				{
					index = j;
					temp = nums[j];
				}
				else
				{
					if (temp > nums[j])
					{
						index = j;
						temp = nums[j];
					}
				}
			}
		}
		int numTemp = nums[index];
		nums[index] = nums[i];
		nums[i] = numTemp;
		reverse(nums.begin() + i + 1, nums.end());
		flag = 1;
		break;
	}
	if (!flag)
	{
		sort(nums.begin(), nums.end());
	}
}
void printVector(vector<int>& vec)
{
	int len = vec.size();
	for (int i = 0; i < len; i++) {
		cout << vec[i];
	}
	cout << endl;
}
void initVector(vector<int>& vec)
{
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(3);
	vec.push_back(9);
	vec.push_back(2);
}
int main01()
{
	//环路检测
	/*ListNode* temp = initList();
	ListNode* res = detectCycle(temp);
	cout << "----------环路的头节点为：-----------" << endl;
	cout << res->val << endl;*/
	//下一个排列
	vector<int>vec;
	initVector(vec);
	cout << "当前的数字：";
	printVector(vec);
	nextPermutation(vec);
	cout << "下一个排列：";
	printVector(vec);
	return 0;
}
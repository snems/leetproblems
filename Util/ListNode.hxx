#ifndef LEETCODE_LISTNODE_HXX
#define LEETCODE_LISTNODE_HXX

#include <initializer_list>
#include <memory>
#include <vector>

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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeCreator
{
private:
	std::vector<std::unique_ptr<ListNode>> nodes;
	ListNode *create_node()
	{
		nodes.emplace_back(std::make_unique<ListNode>());
		return nodes.back().get();
	}
public:
	ListNode *operator()(std::initializer_list<int> list)
	{
		ListNode *result = nullptr;
		ListNode *head = nullptr;

		for (int a: list)
		{
			if (!result)
			{
				head = create_node();
				result = head;
			}
			else
			{
				result->next = create_node();
				result = result->next;
			}
			result->val = a;
		}
		return head;
	}
};

#endif //LEETCODE_LISTNODE_HXX

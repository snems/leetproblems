/*
 * 19. Remove Nth Node From End of List
 * Medium
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 *
 *
 * Example 1:
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 */

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
#include "Util/ListNode.hxx"
#include "Util/catch.hpp"

namespace
{
	class Solution
	{
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n)
		{
			std::vector < ListNode * > cache;
			ListNode *node = head;
			while (node)
			{
				cache.push_back(node);
				node = node->next;
			}
			size_t index_to_delete = cache.size() - n;
			ListNode *result = head->next;
			ListNode *to_delete(cache[index_to_delete]);
			if (index_to_delete)
			{
				result = head;
				ListNode *previous = cache[index_to_delete - 1];
				previous->next = to_delete->next;
			}

			return result;
		}
	};
}

TEST_CASE("Test 19. Remove Nth node from end of list", "[remove-nth-node-from-end-of-list][19]")
{
	ListNodeCreator creator;
	Solution s;

	SECTION("Example 1")
	{
		ListNode *head = creator({1,2,3,4,5});
		ListNode *expected = creator({1,2,3,5});
		CHECK(*expected == *(s.removeNthFromEnd(head, 2)));
	}

	SECTION("Example 1")
	{
		ListNode *head = creator({1,2});
		ListNode *expected = creator({1});
		CHECK(*expected == *(s.removeNthFromEnd(head, 1)));
	}

}


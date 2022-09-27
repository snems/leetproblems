/*
 * 328. Odd Even Linked List
 * Medium
 *
 * Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Note that the relative order inside both the even and odd groups should remain as it was in the input.
 *
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 *
 *
 * Constraints:
 *
 *     The number of nodes in the linked list is in the range [0, 10^4].
 *     -10^6 <= Node.val <= 10^6
 *
 *
 * Example 1:
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 * Example 2:
 *
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
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
#include <iostream>
#include "Util/ListNode.hxx"
#include "Util/catch.hpp"

namespace
{
	class Solution
	{
	public:
		ListNode *oddEvenList(ListNode *head)
		{
			if (!head) return head;
			ListNode *current = head->next;
			ListNode *sort_to = head;
			ListNode *prev = head;
			bool the_flag = false;

			while (current)
			{
				// check is need sort
				if (the_flag)
				{
					// cut node
					ListNode *node = current;
					current = current->next;
					prev->next = current;
					// insert node
					node->next = sort_to->next;
					sort_to->next = node;
					sort_to = node;
				}
				else
				{
					//to next step
					prev = current;
					current = current->next;
				}
				the_flag ^= true;
			}
			return head;
		}
	};
}


TEST_CASE("Test 328. Odd Even Linked List", "[odd_even_linked_list][328]")
{
	ListNodeCreator creator;

	Solution s;

	SECTION("Example 1")
	{
		ListNode *head = creator({1, 2, 3, 4, 5});
		ListNode *expected = creator({1, 3, 5, 2, 4});
		CHECK(*s.oddEvenList(head) == *expected);
	}

	SECTION("Example 2")
	{
		ListNode *head = creator({2,1,3,5,6,4,7});
		ListNode *expected = creator({2,3,6,7,1,5,4});
		CHECK(*s.oddEvenList(head) == *expected);
	}

	SECTION("Zero")
	{
		ListNode *head = creator({});
		ListNode *expected = nullptr;
		CHECK(s.oddEvenList(head) == expected);
	}

	SECTION("One")
	{
		ListNode *head = creator({2});
		ListNode *expected = creator({2});
		CHECK(*s.oddEvenList(head) == *expected);
	}

	SECTION("Two same")
	{
		ListNode *head = creator({2, 2});
		ListNode *expected = creator({2, 2});
		CHECK(*s.oddEvenList(head) == *expected);
	}

	SECTION("Two different")
	{
		ListNode *head = creator({2, 3});
		ListNode *expected = creator({2, 3});
		CHECK(*s.oddEvenList(head) == *expected);
	}

	SECTION("Three")
	{
		ListNode *head = creator({2, 3, 5});
		ListNode *expected = creator({2, 5, 3});
		CHECK(*s.oddEvenList(head) == *expected);
	}


}
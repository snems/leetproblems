/*
 * 234. Palindrome Linked List
 * Easy
 *
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
 *
 *
 * Example 1:
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *     The number of nodes in the list is in the range [1, 10^5].
 *     0 <= Node.val <= 9
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
 */

#include <iostream>
#include "Util/ListNode.hxx"
#include "Util/catch.hpp"

namespace
{
	class Solution
	{
	private:
		size_t center(ListNode *head, ListNode **result)
		{
			size_t cnt = 0;
			ListNode *center = head;
			while (head)
			{
				if (!(cnt%2))
				{
					center = center->next;
				}
				++cnt;
				head = head->next;
			}
			*result = center;
			return cnt;
		}
	public:
		bool isPalindrome(ListNode *head)
		{
			ListNode *a;
			size_t cnt = center(head, &a);
			if (cnt < 2) return true;
			ListNode *b = a->next;
			ListNode *next;
			a->next = nullptr;
			while (b )
			{
				next = b->next;
				b->next = a;
				a = b;
				b = next;
			}
			while(a)
			{
				if (head->val != a->val)
				{
					return false;
				}
				a = a->next;
				head = head->next;
			}
			return true;
		}
	};
}

TEST_CASE("Test 234. Palindrome Linked List", "[palindrome_linked_list][234]")
{
	Solution s;
	ListNodeCreator creator;

	SECTION("My test")
	{
		CHECK(s.isPalindrome(creator({1,2,3,4,4,3,2,1})));
	}

	SECTION("Example 1")
	{
		CHECK(s.isPalindrome(creator({1,2,2,1})));
	}

	SECTION("Example 2")
	{
		CHECK(s.isPalindrome(creator({1,2})) == false);
	}

	SECTION("One")
	{
		CHECK(s.isPalindrome(creator({1})) == true);
	}

	SECTION("Odd")
	{
		CHECK(s.isPalindrome(creator({1,2,1})) == true);
	}
}

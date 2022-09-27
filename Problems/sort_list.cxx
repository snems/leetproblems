/* 148. Sort List
 * Medium
 *
 * Given the head of a linked list, return the list after sorting it in ascending order.
 *
 * Example 1:
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 * Example 2:
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 * Example 3:
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *     The number of nodes in the list is in the range [0, 5 * 104].
 *     -105 <= Node.val <= 105
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/
#include <iostream>
#include "Util/catch.hpp"
#include "Util/ListNode.hxx"

namespace
{
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
	class Solution {
		static size_t positions(ListNode *head, ListNode **center, ListNode *last)
		{
			size_t cnt = 0;
			ListNode *tmp = head;
			while (head && head != last)
			{
				if ((cnt%2))
				{
					tmp = tmp->next;
				}
				++cnt;
				head = head->next;
			}
			*center = tmp;
			return cnt;
		}
		static bool is_need_sort(ListNode *from, ListNode *to)
		{
			if (from == nullptr) return false;
			if (from->next == nullptr) return false;
			if (from == to) return false;
			if ((from->next == to) && (from->val <= to->val)) return false;
			return true;
		}
		static void sort_iter(ListNode *before, ListNode *from, ListNode *center, ListNode *last)
		{
			// if head != center
			if (is_need_sort(from, center))
			{
				ListNode *current = from;
				ListNode *prev = nullptr;
				ListNode *tmp;
				// cycle from head to center
				while (current != center)
				{
					//pre_center = current;
					// move all nodes more than center after center
					if (current->val > center->val)
					{
						if (prev)
						{
							prev->next = current->next;
						}
						if (current == from)
						{
							if (before)
							{
								before->next = current->next;
							}
							from = current->next;
						}
						tmp = current->next;
						current->next = center->next;
						center->next = current;
						current = tmp;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}
			}

			// if center != last
			if (is_need_sort(center, last))
			{
				ListNode *current = center->next;
				ListNode *prev = center;
				ListNode *tmp;
				// cycle from center to last
				while (current != last)
				{
					// move all nodes less than center before center
					if (current->val < center->val)
					{
						prev->next = current->next;
						tmp = current->next;

						current->next = from->next;
						from->next = current;

						current = tmp;
					}
					else
					{
						prev = current;
						current = current->next;
					}
				}
			}
			if (is_need_sort(from, center))
			{
				// spit all the intervals into two new intervals and sort it
				{
					ListNode *new_center = nullptr;
					positions(from, &new_center, center);
					sort_iter(before, from, new_center, center);
				}
			}
			if (is_need_sort(center, last))
			{
				ListNode *pre_center = before;
				ListNode *tmp = from;
				while (tmp != center)
				{
					pre_center = tmp;
					tmp = tmp->next;
				}
				// split all the intervals into two new intervals and sort it
				ListNode *new_center = nullptr;
				positions(center, &new_center, last);
				sort_iter(pre_center, center, new_center, last);
			}
		}
	public:
		ListNode* sortList(ListNode* head) {
			if (!head) return head;
			ListNode to_sort;
			ListNode *center = nullptr;
			to_sort.next = head;
			positions(head, &center, nullptr);
			sort_iter(&to_sort, head, center, nullptr);
			return to_sort.next;
		}
	};
}


TEST_CASE("Test 148. Sort List", "[sort-list][148]")
{
	ListNodeCreator creator;
	Solution solution;

	SECTION("Debug")
	{
		ListNode *head = creator({4, 2, 8, 7, 1, 10, 5});
		ListNode *expected = creator({1, 2, 4, 5, 7, 8, 10});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Example 1")
	{
		ListNode *head = creator({4, 2, 1, 3});
		ListNode *expected = creator({1, 2, 3, 4});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Example 2")
	{
		ListNode *head = creator({-1, 5, 3, 4, 0});
		ListNode *expected = creator({-1, 0, 3, 4, 5});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Example 3")
	{
		ListNode *head = creator({});
		ListNode *expected = nullptr;
		CHECK(solution.sortList(head) == expected);
	}

	SECTION("Same")
	{
		ListNode *head = creator({1, 2, 3, 4, 5, 6, 7});
		ListNode *expected = creator({1, 2, 3, 4, 5, 6, 7});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Reverse")
	{
		ListNode *head = creator({7, 6, 5, 4, 3, 2, 1});
		ListNode *expected = creator({1, 2, 3, 4, 5, 6, 7});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("One")
	{
		ListNode *head = creator({7});
		ListNode *expected = creator({7});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Two")
	{
		ListNode *head = creator({7, 1});
		ListNode *expected = creator({1, 7});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Bug")
	{
		ListNode *head = creator({4, 19, 14, 5, -3, 1, 8, 5, 11, 15});
		ListNode *expected = creator({-3, 1, 4, 5, 5, 8, 11, 14, 15, 19});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Many same")
	{
		ListNode *head = creator    ({10,5,5,5,5,2});
		ListNode *expected = creator({2, 5,5,5,5, 10});
		CHECK(*solution.sortList(head) == *expected);
	}

	SECTION("Bug 2")
	{
		ListNode *head = creator(
		{-84, 142, 41, -17, -71, 170, 186, 183, -21, -76, 76, 10, 29, 81, 112, -39, -6, -43, 58, 41, 111, 33, 69, 97, -38, 82, -44, -7, 99, 135, 42, 150, 149, -21, -30, 164, 153,
		 92, 180, -61, 99, -81, 147, 109, 34, 98, 14, 178, 105, 5, 43, 46, 40, -37, 23, 16, 123, -53, 34, 192, -73, 94, 39, 96, 115, 88, -31, -96, 106, 131, 64, 189, -91, -34, -56,
		 -22, 105, 104, 22, -31, -43, 90, 96, 65, -85, 184, 85, 90, 118, 152, -31, 161, 22, 104, -85, 160, 120, -31, 144, 115});
		ListNode *expected = creator({-96, -91, -85, -85, -84, -81, -76, -73, -71, -61, -56, -53, -44, -43, -43, -39, -38, -37, -34, -31, -31, -31, -31, -30, -22, -21, -21, -17, -7, -6, 5, 10, 14, 16, 22, 22, 23, 29, 33, 34, 34, 39, 40, 41, 41, 42, 43, 46, 58, 64, 65, 69, 76, 81, 82, 85, 88, 90, 90, 92, 94, 96, 96, 97, 98, 99, 99, 104, 104, 105, 105, 106, 109, 111, 112, 115, 115, 118, 120, 123, 131, 135, 142, 144, 147, 149, 150, 152, 153, 160, 161, 164, 170, 178, 180, 183, 184, 186, 189, 192});
		CHECK(*solution.sortList(head) == *expected);
	}

}

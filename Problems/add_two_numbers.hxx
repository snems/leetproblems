#ifndef LEETCODE_ADD_TWO_NUMBERS_HXX
#define LEETCODE_ADD_TWO_NUMBERS_HXX

#include "Util/ListNode.hxx"

class add_two_numbers
{
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			return nullptr;
		}
	};
	void operator()()
	{
		ListNodeCreator creator;
		ListNode *list1 = creator({1,2,3,4,5});
		ListNode *list2 = creator({1,2,3,4,5});
		Solution sol;
		ListNode *result = sol.addTwoNumbers(list1, list2);
	}
};

#endif //LEETCODE_ADD_TWO_NUMBERS_HXX

#include "ListNode.hxx"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const ListNode& node)
{
	ListNode n = node;
	ListNode *ptr = &n;
	while (ptr)
	{
		os << ptr->val;
		if (ptr->next) os << ", ";
		ptr = ptr->next;
	};
	return os;
}

#include "TreeNode.hxx"
#include <ostream>


std::ostream &operator<<(std::ostream &os, const TreeNode &node)
{
	std::queue<std::string> qs;
	std::queue<const TreeNode*> q;

	q.push(&node);
	while(!q.empty())
	{
		if (q.front() != nullptr)
		{
			qs.push(std::to_string(q.front()->val));
			q.push(q.front()->left);
			q.push(q.front()->right);
		}
		else
		{
			qs.push("nullptr");
		}
		q.pop();
	}

	while (!qs.empty())
	{
		os << qs.front();
		qs.pop();
		if (!qs.empty()) os << ", ";
	}
	return os;
}

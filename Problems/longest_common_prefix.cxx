/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *      Input: strs = ["flower","flow","flight"]
 *      Output: "fl"
 *
 * Example 2:
 *
 * Input: strs = ["dog","racecar","car"]
 *      Output: ""
 *      Explanation: There is no common prefix among the input strings.
 *
 *
 * Constraints:
 *     1 <= strs.length <= 200
 *     0 <= strs[i].length <= 200
 *     strs[i] consists of only lowercase English letters.
 *
 *
 */
#include "Util/catch.hpp"
#include <string>
#include <vector>

namespace
{
	class Solution {
	public:
		std::string longestCommonPrefix(std::vector<std::string>& strs) {
			std::string result = strs[0];
			for (const auto &s: strs)
			{
				if (result.size() < s.size())
				{
					result.resize(s.size());
				}
				for (size_t i = 0; i < result.size(); ++i)
				{
					if (result[i] != s[i])
					{
						result.resize(i);
					}
				}
				if (result.empty())
				{
					break;
				}
			}
			return result;
		}
	};
}

TEST_CASE("Test 14. Longest common prefix", "[longest-common-prefix][14]")
{
	Solution s;

	SECTION("Example 1")
	{
		std::vector<std::string> strings = {"flower", "flow", "flight"};
		CHECK(s.longestCommonPrefix(strings) == "fl");
	}

	SECTION("Example 2")
	{
		std::vector<std::string> strings = {"dog", "racecar", "car"};
		CHECK(s.longestCommonPrefix(strings) == "");
	}

	SECTION("One element")
	{
		std::vector<std::string> strings = {"one"};
		CHECK(s.longestCommonPrefix(strings) == "one");
	}

	SECTION("Descending")
	{
		std::vector<std::string> strings = {"abcdef", "abcdez", "abcezz", "abczzz", "azzzzz"};
		CHECK(s.longestCommonPrefix(strings) == "a");
	}
}
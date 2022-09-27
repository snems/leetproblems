/*
 * 2131. Longest Palindrome by Concatenating Two Letter Words
 * Medium
 *
 * You are given an array of strings words. Each element of words consists of two lowercase English letters.
 *
 * Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
 *
 * Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
 *
 * A palindrome is a string that reads the same forward and backward.
 *
 *
 *
 * Example 1:
 *
 * Input: words = ["lc","cl","gg"]
 * Output: 6
 * Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
 * Note that "clgglc" is another longest palindrome that can be created.
 *
 * Example 2:
 *
 * Input: words = ["ab","ty","yt","lc","cl","ab"]
 * Output: 8
 * Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
 * Note that "lcyttycl" is another longest palindrome that can be created.
 *
 * Example 3:
 *
 * Input: words = ["cc","ll","xx"]
 * Output: 2
 * Explanation: One longest palindrome is "cc", of length 2.
 * Note that "ll" is another longest palindrome that can be created, and so is "xx".
 *
 *
 *
 * Constraints:
 *
 * 1 <= words.length <= 105
 * words[i].length == 2
 * words[i] consists of lowercase English letters.

*/
#include <unordered_map>
#include "Util/catch.hpp"

namespace
{
class Solution {
public:
	bool is_sim(const std::string &s)
	{
		return s[0] == s[1];
	}
	std::string anagram(std::string s)
	{
		std::swap(s[0], s[1]);
		return s;
	}
    int longestPalindrome(std::vector<std::string>& words) {
		int result = 0;
	    bool was_single_ana = false;
		std::unordered_map<std::string, int> map;
		for (const auto &w: words)
		{
			++map[w];
		}

		while(!map.empty())
		{
			const std::string str = map.begin()->first;
			const std::string &ana = anagram(str);

			if (--map.begin()->second == 0)
				map.erase(map.begin());

			if (map.count(ana))
			{
				result += 4;
				if (--map[ana] == 0) map.erase(ana);
			}
			else if (is_sim(str) && !was_single_ana)
			{
				was_single_ana = true;
				result +=2;
			}
		}
		return result;
    }
};
}

TEST_CASE("Test 2131. Longest common prefix", "[longest-common-prefix][2131]")
{

	Solution solution;

	SECTION("Example 1")
	{
		std::vector<std::string> words = {"lc","cl","gg"};
		CHECK(solution.longestPalindrome(words) == 6);
	}

	SECTION("Example 1")
	{
		std::vector<std::string> words = {"ab","ty","yt","lc","cl","ab"};
		CHECK(solution.longestPalindrome(words) == 8);
	}

	SECTION("Example 1")
	{
		std::vector<std::string> words = {"cc","ll","xx"};
		CHECK(solution.longestPalindrome(words) == 2);
	}

	SECTION("One")
	{
		std::vector<std::string> words = {"ca"};
		CHECK(solution.longestPalindrome(words) == 0);
	}

	SECTION("One symmetric")
	{
		std::vector<std::string> words = {"cc"};
		CHECK(solution.longestPalindrome(words) == 2);
	}

	SECTION("Two same")
	{
		std::vector<std::string> words = {"aa", "aa"};
		CHECK(solution.longestPalindrome(words) == 4);
	}

	SECTION("Two same with sym")
	{
		std::vector<std::string> words = {"aa", "aa", "dd"};
		CHECK(solution.longestPalindrome(words) == 6);
	}

	SECTION("Two same with not sym")
	{
		std::vector<std::string> words = {"aa", "aa", "dx"};
		CHECK(solution.longestPalindrome(words) == 4);
	}

	SECTION("Three same")
	{
		std::vector<std::string> words = {"aa", "aa", "aa"};
		CHECK(solution.longestPalindrome(words) == 6);
	}

	SECTION("Same uneven")
	{
		std::vector<std::string> words = {"ra", "ra", "ra"};
		CHECK(solution.longestPalindrome(words) == 0);
	}

	SECTION("Same uneven 2")
	{
		std::vector<std::string> words = {"ra", "ar", "ar"};
		CHECK(solution.longestPalindrome(words) == 4);
	}
}

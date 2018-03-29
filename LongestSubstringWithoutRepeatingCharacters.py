"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

"""

class Solution(object):
    '''Solution class'''
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLength = 0
        window = ''
        str_len = len(s)
        
        if str_len < 2:
            return str_len
        if str_len == 2:
            if s[0] == s[1]:
                return 1
            return 2

        for i in range(len(s)):
            if s[i] not in window:
                window += s[i]
            else:
                left = window.index(s[i])
                window = window[left+1:]
                window += s[i]

            maxLength = max(maxLength, len(window))

        return maxLength


if __name__ == "__main__":
    sol = Solution()
    print sol.lengthOfLongestSubstring('abcabcbb')
    print sol.lengthOfLongestSubstring('bbbbb')
    print sol.lengthOfLongestSubstring('pwwkew')
    print sol.lengthOfLongestSubstring('aab')
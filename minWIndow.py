import sys

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        dict_s = {}
        for i in s:
            dict_s[i] = 0
        for i in t:
            if i in dict_s: dict_s[i] += 1
            else: return ""
        
        start = 0
        end = 0
        minStart = 0
        minLen = sys.maxint
        numberofTargets = len(t)
        
        while(end < len(s)):
            current = s[end]
            if dict_s[current] > 0:
                numberofTargets -= 1
            dict_s[current] -= 1
            while numberofTargets == 0:
                if minLen > end - start + 1:
                    minLen = end - start + 1
                    minStart = start
                head = s[start]
                if dict_s[head] >= 0:
                    numberofTargets += 1
                dict_s[head] += 1
                start += 1
            end += 1
        if minLen == sys.maxint: return ""
        return s[minStart:minStart+minLen]

def main():
    sol = Solution();
    print sol.minWindow("ADOBECODEBANC", "ABC")

if __name__ == '__main__':
    main()
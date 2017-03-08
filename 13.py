#!/usr/bin/python

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ROMAN = {"M":1000, "D":500, "C":100, "L":50, "X":10, "V":5, "I":1}
        value = 0

        for i in range(0, len(s)-1):
        	if (ROMAN[s[i]] < ROMAN[s[i+1]]):
        		value -= ROMAN[s[i]]
        	else:
        		value += ROMAN[s[i]]
        
        return value + ROMAN[s[len(s)-1]]



if __name__=='__main__':
    solution = Solution()
    # s = "DCXXI"
    s = "XXIX"
    print solution.romanToInt(s)
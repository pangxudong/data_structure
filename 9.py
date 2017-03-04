#!/usr/bin/python

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x==0:
            return True

        if x>0:
            strx = str(x)
            stry = strx[::-1]
            y = int(stry)
            if x==y:
                return True

        if x<0:
            x = -x
            strx = str(x)
            stry = strx[::-1]
            y = int(stry)
            y = -y
            if x==y:
                return True

        return False
        
        



if __name__=='__main__':
    solution = Solution()
    # x = 1000000001
    # x = 0
    # x = 10100
    # x = -123
    x = -2147483648
    print solution.isPalindrome(x)
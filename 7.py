#!/usr/bin/python

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        MAXINT = 2147483647
        MININT = -2147483648
        if x==0:
            return 0

        if x>0:
            strx = str(x)
            stry = strx[::-1]
            y = int(stry)
            if (y>MAXINT):
                return 0
            return y

        if x<0:
            x = -x
            strx = str(x)
            stry = strx[::-1]
            y = int(stry)
            y = -y
            if y<MININT:
                return 0
            return y
        



if __name__=='__main__':
    solution = Solution()
    x = 1000000003
    # x = 0
    # x = 10100
    # x = -123
    # x = -10100
    print solution.reverse(x)
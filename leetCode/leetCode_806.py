import string

class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        
        X = [string.lowercase.index(x) for x in S]
        print X
        
        Y = [widths[i] for i in X] 
        print Y
        
        totalSum = sum(Y)
        print totalSum
        
        quotient = totalSum/100
        remainder = totalSum%100
        
        print quotient
        print remainder
        
        a = 0
        b = 0
        tempSum = 0
        
        for i in Y:
            tempSum += i
            if tempSum > 100:
                tempSum = i
                a += 1
                
            b = tempSum
                
        return [a+1,b]
        
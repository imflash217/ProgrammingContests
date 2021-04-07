#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Given a non-negative integer num, return the number of steps to reduce it to zero.
If the current number is even, you have to divide it by 2, 
otherwise, you have to subtract 1 from it.
"""

class Solution:
    def numberOfSteps_naive(self, num: int) -> int:
        # time = O(log_n)
        # space = O(1)
        #
        count = 0
        while num > 0:
            if num % 2 == 0:
                # number is even; so divide by 2
                num = num // 2
            else:
                # number is odd; so subtract 1
                num -= 1
            count += 1  # increment the counter
        return count 

    def numberOfSteps_bit_manipulation(self, num: int) -> int:
        # using bit manipulation
        # time = O(log_n)
        # space = O(log_n)
        #
        # step-1: convert decimal to binary
        binary = bin(num)[2:]
        print(binary)
        count = 0
        for bit in binary:
            if bit == "1":
                # it will take two steps to remove it
                # first we have to subtract 1
                # then we have to shift 1 bit right (i.e. divide by 2)
                # so two steps needed
                count += 2
            else:
                # bit is 0, so we just reed to shift right by 1 bit
                # so just 1 step
                count += 1
        # if last bit is "1" the we need only 1 step (i.e. subtract)
        # if last bit is "0" then we don't need any step 
        # so decrement the count by 1
        return count - 1

    def numberOfSteps_bit_op(self, num: int) -> int:
        # bit manipulation
        if num == 0:
            return 0
        
        mask = 1
        count = 0
        while mask <= num:
            if (num & mask) == 0:
                count += 1
            else:
                count += 2
            mask *= 2
        return count - 1



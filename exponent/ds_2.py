## @imflash217
##
## creating a new file
with open("numbers.txt", "w") as file:
    for i in range(1000):
        print(str(i), file=file)

##################################################################


def find_max(input):
    max_num = float("-inf")

    for x in input:
        if x > max_num:
            max_num = x
    return max_num


#################################################################

import heapq


def find_largest(input, m):
    max_nums = [float("-inf")]
    for x in input:
        ## checking with the root of the heap to find the smallest
        if int(x) > max_nums[0]:
            if len(max_nums) >= m:  ## maintaining the heap size
                heapq.heappop(max_nums)  ## remove the smallest from the heap
            heapq.heappush(max_nums, int(x))  ## push the new number
    return max_nums


#################################################################

if __name__ == "__main__":
    with open("./numbers.txt", "r") as file:
        results = find_largest(file, 5)
    print(results)

#################################################################

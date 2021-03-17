########################################################################
# Write a function diff(arrA, arrB) that accepts two arrays and returns a
# new array that contains all values that are not contained in both input arrays.
# The order of numbers in the result array does not matter.
########################################################################

## Solution-1: Brute-force


def diff_1(arrA, arrB):
    """
    Runtime: O(n^2)
    """
    results = []

    ## iterate over arrA and look if its elements don't belong to arrB
    for x in arrA:
        if x not in arrB:
            results.append(x)

    ## repeat the same for arrB
    for x in arrB:
        if x not in arrA:
            results.append(x)

    return results


########################################################################
## Solution-2: Using hash-table


def diff_2(arrA, arrB):
    """
    Runtime: O(n)
    """

    results = []
    hashA = {n: True for n in arrA}
    hashB = {n: True for n in arrB}

    for x, _ in hashA.items():
        if x not in hashB:
            results.append(x)
    for x, _ in hashB.items():
        if x not in hashA:
            results.append(x)
    return results


########################################################################
## Solution-3: Set Difference


def diff_3(arrA, arrB):
    """
    Using XOR
    """
    return list(set(arrA) ^ set(arrB))


########################################################################

if __name__ == "__main__":
    a = [1, 2, 1, 2, 3, 4]
    b = [2, 1, 2, 100, 32]
    print(diff_1(a, b))
    print(diff_2(a, b))
    print(diff_3(a, b))

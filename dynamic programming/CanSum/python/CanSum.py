


def canSum(targetSum, numbers):
    return can_sum_rec(targetSum, numbers, {})

def can_sum_rec(targetSum, numbers, memo):
    if targetSum in memo:
        return memo[targetSum]
    if targetSum == 0:
        return True

    if targetSum < 0:
        return False

    if min(numbers) > targetSum:
        return False

    for number in numbers:
        
        if can_sum_rec(targetSum - number, numbers, memo):
            memo[targetSum ] = True
            return memo[targetSum]
    memo[targetSum] = False
    return False

print( canSum(7, [2, 3])) # True
print( canSum(7, [5, 3, 4, 7])) # True
print( canSum(7, [2, 4])) # False
print( canSum(8, [2, 3, 5])) # True
print( canSum(300, [7, 14])) # False

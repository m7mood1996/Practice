

def howSum(targetSum, numbers):
    return how_sum_rec(targetSum, numbers, {})

def how_sum_rec(targetSum, numbers, memo):
    if targetSum in memo:
        return memo[targetSum]
    if targetSum == 0:
        return []

    if targetSum < 0:
        return None

    if min(numbers) > targetSum:
        return None

    for number in numbers:
        remains = targetSum - number
        arr = how_sum_rec(remains, numbers, memo)
        if not arr == None:
            arr.append(number)
            memo[targetSum ] = arr
            return memo[targetSum]
    memo[targetSum] = None
    return None

print( howSum(7, [2, 3])) # True
print( howSum(7, [5, 3, 4, 7])) # True
print( howSum(7, [2, 4])) # False
print( howSum(8, [2, 3, 5])) # True
print( howSum(300, [7, 14])) # False
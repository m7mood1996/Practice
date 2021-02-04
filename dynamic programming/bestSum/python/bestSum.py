

def bestSum(targetSum, numbers):
    return best_sum_rec(targetSum, numbers, {})

def best_sum_rec(targetSum, numbers, memo):
    if targetSum in memo:
        return list(memo[targetSum])
    if targetSum == 0:
        return []

    if targetSum < 0:
        return None

    if min(numbers) > targetSum:
        return None
    array_of_arrays = []
    for number in numbers:
        remains = targetSum - number
        arr = best_sum_rec(remains, numbers, memo)
        if not arr == None:
            arr.append(number)
            array_of_arrays.append(arr)
            
    i = 0
    for i, array in enumerate(array_of_arrays):
        if not array == None:
            break
        if i == len(array_of_arrays) -1 and array == None:
            memo[targetSum] = None
            return None
    
    min_len = len(array_of_arrays[i])
    min_index = i
    for index in range(i, len(array_of_arrays)):
        if array_of_arrays[index] == None:
            continue
        else:
            if min_len > len(array_of_arrays[index]):
                min_len = len(array_of_arrays[index])
                min_index = index
    
    memo[targetSum] = list(array_of_arrays[min_index])
    return list(array_of_arrays[min_index])

    

print( bestSum(7, [5, 3, 4, 7])) # [7]
print( bestSum(8, [2, 3, 5])) # [3, 5]
print( bestSum(8, [1, 4, 5])) # [4, 4]

print( bestSum(100, [1, 2, 5, 25])) # [25, 25, 25, 25]
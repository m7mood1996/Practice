



def gridTraveler(n, m, memo = {(0,0) : 0, (1,1): 1}):

    if n == 0 or m == 0:
        return 0
    if n == 1 and m == 1:
        return 1
    else:
        if memo.get((n, m)):
            return memo[(n, m)]
        else:
            memo[(n, m)] = gridTraveler(n - 1, m, memo) + gridTraveler(n, m - 1, memo)
            return memo[(n, m)]

print(gridTraveler(1,1)) ## 1
print(gridTraveler(2,3)) ## 3
print(gridTraveler(3,3)) ## 6
print(gridTraveler(18,18)) ## 2333606220
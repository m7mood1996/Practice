"""
practice dynamic programming fibonacci function
"""


# dynamic programming fibonacci

def fib(n, memo={1 : 1, 2 : 1}):
    if n <= 2:
        return memo[n]
    else:
        if memo.get(n):
            return memo[n]
        
        else:
            memo[n] = fib(n - 1, memo) + fib(n - 2, memo)
            return memo[n]


print(fib(50))


 
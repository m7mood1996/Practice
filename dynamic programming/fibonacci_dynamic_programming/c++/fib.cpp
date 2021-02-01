
#include <iostream>
#include <vector>

size_t fib(size_t n,std::vector<size_t>&memo)
{
    if (n <= 2)
    {
        return memo[n];
    }
    else
    {
        if (n < memo.size())
            return memo[n];
        memo.push_back( fib(n - 1, memo) + fib(n - 2, memo));
        return memo[n];
    }
}




int main()
{
    std::vector<size_t> mem;
    mem.push_back(1);
    mem.push_back(1);
    mem.push_back(1);
    std::cout << fib(50, mem) << std::endl;
    return 0;
}


#include <iostream>
#include <string>
#include <unordered_map>

size_t gridTraveler(size_t n, size_t m, std::unordered_map<std::string, size_t>& memo)
{
    std::string key = std::to_string(n) + "," + std::to_string(m);
    if (n == 0 or m == 0)
    {
        return 0;
    }

    try
    {
        return memo.at(key);
    }
    catch(const std::exception& e)
    {
        memo[key] = gridTraveler(n - 1, m , memo) + gridTraveler(n, m - 1, memo);
        return memo[key];
    }
    
    
}



int main()
{
    std::unordered_map<std::string, size_t> memo;
    memo["0,0"] = 0;
    memo["1,0"] = 0;
    memo["0,1"] = 0;
    memo["1,1"] = 1;

    std::cout << gridTraveler(1,1,memo) << std::endl; // 1
    std::cout << gridTraveler(2,3,memo) << std::endl; // 3
    std::cout << gridTraveler(3,2,memo) << std::endl; // 3
    std::cout << gridTraveler(3,3,memo) << std::endl; // 6
    std::cout << gridTraveler(18,18,memo) << std::endl; // 2333606220



    return 0;
}
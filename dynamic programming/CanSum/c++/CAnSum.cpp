#include <iostream>
#include <map>

bool how_sum_rec(int targetNumber, int numbers[], size_t size, std::map<int, bool> *memo )
{
    try
    {
        return memo->at(targetNumber);
    }
    catch(const std::exception& e)
    {

        if (targetNumber == 0)
            return true;

        if (targetNumber < 0)
            return false;

        size_t i = 0;
        for (; i < size; ++i)
        {
            int reminder = targetNumber - numbers[i];
            try
            {
                return memo->at(reminder);
            }
            catch(const std::exception& e)
            {
                bool k = how_sum_rec(reminder, numbers, size, memo);
                (*memo)[reminder] = k;
                if (k)
                    return true;
            }

        }

        (*memo)[targetNumber] = false;
        return false;
    }


}


bool howSum(int targetNumber, int numbers[], size_t size)
{
    std::map<int, bool> memo;
    return how_sum_rec(targetNumber, numbers, size, &memo);
}



int main()
{
    int a[] = {2, 3};
    int b[] = {5, 3, 4, 7};
    int c[] = {2, 4};
    int d[] = {2, 3, 5};
    int e[] = {7, 14};
    std::cout << howSum(7, a, 2) << std::endl; // true
    std::cout << howSum(7, b, 4) << std::endl; // true
    std::cout << howSum(7, c, 2) << std::endl; // false
    std::cout << howSum(8, d, 3) << std::endl; // true
    std::cout << howSum(300, e, 2) << std::endl; // false

    return 0;
}

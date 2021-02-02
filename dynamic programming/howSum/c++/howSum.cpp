#include <iostream>
#include <map>
#include <vector>

std::vector<int> how_sum_rec(int targetNumber, int numbers[], size_t size, std::map<int, std::vector<int> > *memo )
{
    try
    {
        return memo->at(targetNumber);
    }
    catch(const std::exception& e)
    {

        if (targetNumber == 0)
            return std::vector<int>();

        if (targetNumber < 0)
        {
            std::vector<int> v;
            v.push_back(-1);
            return v;
        }


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
                std::vector<int> arr = how_sum_rec(reminder, numbers, size, memo);
                if (arr.empty() or arr[0] != -1)
                {
                    arr.push_back(numbers[i]);
                    (*memo)[reminder] = arr;
                    return arr;
                }
            }

        }

        std::vector<int> v;
        v.push_back(-1);

        (*memo)[targetNumber] = v;
        return v;
    }


}


std::vector<int> howSum(int targetNumber, int numbers[], size_t size)
{
    std::map<int, std::vector<int> > memo;
    return how_sum_rec(targetNumber, numbers, size, &memo);
}


void print_vector(std::vector<int>& v)
{
    size_t i =0;
    for(;i < v.size(); ++i)
    {
        std::cout << v[i] << "," ;
    }
    std::cout << std::endl;
}

int main()
{
    int a[] = {2, 3};
    int b[] = {5, 3, 4, 7};
    int c[] = {2, 4};
    int d[] = {2, 3, 5};
    int e[] = {7, 14};
    std::vector<int> v =  howSum(7, a, 2);
    print_vector(v);
    v = howSum(7, b, 4);
    print_vector(v);
    v = howSum(7, c, 2);
    print_vector(v);
    v = howSum(8, d, 3);
    print_vector(v);
    v = howSum(300, e, 2);
    print_vector(v);

    return 0;
}

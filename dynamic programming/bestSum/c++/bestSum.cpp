#include <iostream>
#include <map>
#include <vector>

int getMin(int numbers[], size_t size)
{
    int min = numbers[0];
    size_t i = 1;
    for(;i<size;++i)
    {
        if (numbers[i] < min)
            min = numbers[i];

    }
    return min;

}

std::vector<int> best_sum_rec(int targetNumber, int numbers[], size_t size, std::map<int, std::vector<int> > *memo )
{
    try
    {
        return std::vector<int>(memo->at(targetNumber));
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
        if (getMin(numbers, size) > targetNumber)
        {
            std::vector<int> v;
            v.push_back(-1);
            return v;
        }

        std::vector< std::vector<int> > vect;
        int i = 0;
        for (; i < size; ++i)
        {
            int reminder = targetNumber - numbers[i];
            try
            {

                std::vector<int> arr = memo->at(reminder);
                if (arr.empty() or arr[0] != -1)
                {
                    arr.push_back(numbers[i]);
                    vect.push_back(arr);
                    
                }
            }
            catch(const std::exception& e)
            {
                std::vector<int> arr = best_sum_rec(reminder, numbers, size, memo);
                if (arr.empty() or arr[0] != -1)
                {
                    arr.push_back(numbers[i]);
                    vect.push_back(arr);
                    
                }
            }

        }
        i = 0;
        for (; i < vect.size(); ++i)
        {
            if (!vect[i].empty() and vect[i][0] != -1)
            {
                break;
            }

            if (!vect[i].empty() and vect[i][0] == -1)
                continue;
            if (i == vect.size() - 1 and vect[i][0] == -1)
            {
                std::vector<int> v;
                v.push_back(-1);
                (*memo)[targetNumber] = v;
                return v;
            }
        }

        int min_len = vect[i].size();
        int min_index = i;
        while( i < vect.size())
        {
            if (!vect[i].empty() and vect[i][0] == -1)
            {   ++i;
                continue;
            }
            else
            {
                if (min_len > vect[i].size())
                {
                    min_len = vect[i].size();
                    min_index = i;
                }
            }

            ++i;
        }
        std::vector<int> v(vect[min_index]);
        (*memo)[targetNumber] = v;
        return v;
    }


}


std::vector<int> bestSum(int targetNumber, int numbers[], size_t size)
{
    std::map<int, std::vector<int> > memo;
    return best_sum_rec(targetNumber, numbers, size, &memo);
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
    int a[] = {5, 3, 4, 7};
    int b[] = {2, 3, 5};
    int c[] = {1, 4, 5};
    int d[] = {1, 2, 5, 25};
    std::vector<int> v =  bestSum(7, a, 4);
    print_vector(v);
    v = bestSum(8, b, 3);
    print_vector(v);
    v = bestSum(8, c, 3);
    print_vector(v);
    v = bestSum(100, d, 4);
    print_vector(v);

    return 0;
}

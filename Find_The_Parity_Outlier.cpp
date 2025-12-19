#include <iostream>
#include <vector>
#include <cassert>

int FindOutlier(std::vector<int> arr)
{
    int result = 0;

    int evenCount = 0;
    int oddCount = 0;
    int evenIndex = 0;
    int oddIndex = 0;

    for (size_t i = 0; i < arr.size(); ++i)
    {

        if (arr[i] % 2 == 0)
        {
            evenCount++;
            evenIndex = i;
        }
        else
        {
            oddCount++;
            oddIndex = i;
        }

        if ((evenCount >= 2 && oddCount < 2) || (oddCount >= 2 && evenCount < 2))
        {
            if (evenCount >= 2 && oddCount > 0)
            {
                result = arr[oddIndex];
                break;
            }
            else if (oddCount >= 2 && evenCount > 0)
            {
                result = arr[evenIndex];
                break;
            }
            else
            {
                continue;
            }
        }
    }

    return result;
}

void test_for(std::vector<int> arr, int result)
{
    std::cout << "Testing for {";
    std::string cone = ", ";
    for (std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); ++i)
    {
        if (*i == arr.rbegin()[0])
            cone = "";
        std::cout << *i << cone;
    }
    std::cout << "}" << std::endl;
    assert(FindOutlier(arr) == (result));
}

int main()
{
    test_for({2, 3, 4}, 3);
    test_for({1, 2, 3}, 2);
    test_for({4, 1, 3, 5, 9}, 4);

    std::cout << "all tests passed!" << std::endl;

    return 0;
}
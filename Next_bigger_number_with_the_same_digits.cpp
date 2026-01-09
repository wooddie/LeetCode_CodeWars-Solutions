#include <iostream>
#include <cassert>
#include <algorithm>

long nextBigger(long n)
{
    std::string num = std::to_string(n);
    bool flag = false;

    for (int i = num.size() - 1; i > 0; --i)
    {
        if (num[i - 1] - '0' < num[i] - '0')
        {
            int pivot = num[i - 1] - '0';
            int pivotIndex = i - 1;
            int swapIndex = -1;

            for (int j = i; j < num.size(); ++j)
            {
                if (num[j] - '0' > pivot)
                {
                    if (swapIndex == -1 || num[j] - '0' < num[swapIndex] - '0')
                    {
                        swapIndex = j;
                    }
                }
            }

            std::swap(num[pivotIndex], num[swapIndex]);
            std::sort(num.begin() + i, num.end());

            flag = true;
            break;
        }
    }

    if (!flag)
    {
        return -1;
    }

    return std::stol(num);
}

int main()
{
    assert(nextBigger(12) == (21));
    assert(nextBigger(513) == (531));
    assert(nextBigger(2017) == (2071));
    assert(nextBigger(414) == (441));
    assert(nextBigger(144) == (414));
    assert(nextBigger(10990) == (19009));

    std::cout << "all tests passed!" << std::endl;

    return 0;
}
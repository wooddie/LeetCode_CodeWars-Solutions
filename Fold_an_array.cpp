#include <iostream>
#include <cassert>
#include <vector>

class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
        while (runs > 0 && array.size() > 1)
        {
            int left = 0;
            int right = array.size() - 1;

            while (left < right)
            {
                array[left] += array[right];
                left++;
                right--;
            }

            array.resize(left + (left == right ? 1 : 0));

            runs--;
        }

        return array;
    }
};

int main()
{
    Kata kata;

    // ExampleTest1
    std::vector<int> expected = {6, 6, 3};
    std::vector<int> actual = kata.foldArray({1, 2, 3, 4, 5}, 1);
    assert(actual == (expected));

    // ExampleTest2
    expected = {9, 6};
    actual = kata.foldArray({1, 2, 3, 4, 5}, 2);
    assert(actual == (expected));

    // ExampleTest3
    expected = {15};
    actual = kata.foldArray({1, 2, 3, 4, 5}, 3);
    assert(actual == (expected));

    // ExampleTest4
    expected = {14, 75, 0};
    actual = kata.foldArray({-9, 9, -8, 8, 66, 23}, 1);
    assert(actual == (expected));

    return 0;
}
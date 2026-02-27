#include <iostream>
#include <string>

void makeTree(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    makeTree(5);

    return 0;
}
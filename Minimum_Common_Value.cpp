#include <iostream>
#include <vector>

class Solution
{
public:
    int getCommon(std::vector<int> &nums1, std::vector<int> &nums2)
    {

        size_t i = 0;
        size_t j = 0;

        while (i != nums1.size() && j != nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s1;

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {2, 4};
    std::cout << s1.getCommon(vec1, vec2) << std::endl;

    vec1 = {1, 2, 3, 6};
    vec2 = {2, 3, 4, 5};
    std::cout << s1.getCommon(vec1, vec2) << std::endl;

    return 0;
}
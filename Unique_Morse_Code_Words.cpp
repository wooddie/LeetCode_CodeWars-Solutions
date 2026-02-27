#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int uniqueMorseRepresentations(std::vector<std::string> &words)
    {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        std::unordered_set<std::string> uniqueMorse;

        for (const auto &w : words)
        {
            std::string morseWord;

            for (const char c : w)
            {
                morseWord += morse[c - 'a'];
            }

            uniqueMorse.insert(morseWord);
        }

        return uniqueMorse.size();
    }
};

int main()
{
    Solution s1;

    std::vector<std::string> vec = {"gin", "zen", "gig", "msg"};
    std::cout << s1.uniqueMorseRepresentations(vec) << std::endl;

    vec = {"a"};
    std::cout << s1.uniqueMorseRepresentations(vec) << std::endl;

    return 0;
}
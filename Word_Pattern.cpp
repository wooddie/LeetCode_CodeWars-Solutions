#include <iostream>
#include <sstream>
#include <string>

class Solution
{
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;

        while (ss >> word)
            words.push_back(word);

        if (pattern.length() != words.size())
        {
            return false;
        }

        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i)
        {
            char c = pattern[i];
            std::string w = words[i];

            if (!charToWord.count(c) && !wordToChar.count(w))
            {
                charToWord[c] = w;
                wordToChar[w] = c;
            }

            if (charToWord.count(c))
            {
                if (charToWord[c] != w)
                    return false;
            }
            else
            {
                charToWord[c] = w;
            }

            if (wordToChar.count(w))
            {
                if (wordToChar[w] != c)
                    return false;
            }
            else
            {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};

int main()
{
    Solution s1;

    std::cout << std::boolalpha << s1.wordPattern("abba", "dog cat cat dog") << std::endl;
    std::cout << std::boolalpha << s1.wordPattern("abba", "dog cat cat fish") << std::endl;
    std::cout << std::boolalpha << s1.wordPattern("aaaa", "dog cat cat dog") << std::endl;

    return 0;
}
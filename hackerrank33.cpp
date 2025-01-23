#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

std::pair<std::string, int> countMostFrequentWord(const std::string& sentence) 
{
    std::unordered_map<std::string, int> wordCount;
    std::istringstream stream(sentence);
    std::string word;
    std::string mostFrequentWord;
    int maxCount = 0;

    while (stream >> word) 
    {
        wordCount[word]++;
        if (wordCount[word] > maxCount) 
        {
            maxCount = wordCount[word];
            mostFrequentWord = word;
        }
    }

    return {mostFrequentWord, maxCount};
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); 

    std::vector<std::pair<std::string, int>> results;
    for (int i = 0; i < t; ++i) 
    {
        std::string sentence;
        std::getline(std::cin, sentence);
        results.push_back(countMostFrequentWord(sentence));
    }

    for (const auto& result : results) 
    {
        std::cout << result.first << " " << result.second << std::endl;
    }

    return 0;
}

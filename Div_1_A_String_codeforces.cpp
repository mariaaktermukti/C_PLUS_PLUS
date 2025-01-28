#include <iostream>
#include <vector>
#include <string>

int countOperations(const std::string& s) {
    int count = 0;
    bool inBlock = false;

    for (char c : s) {
        if (c == '1') {
            if (!inBlock) {
                inBlock = true;
                count++;
            }
        } else {
            inBlock = false;
        }
    }

    return count;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); 
    std::vector<int> results;

    for (int i = 0; i < t; ++i) {
        std::string s;
        std::getline(std::cin, s);
        std::cout << "Processing string: " << s << std::endl; 
        results.push_back(countOperations(s));
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}

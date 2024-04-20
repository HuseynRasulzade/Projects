#include "Trie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm> // Include this for std::sort, although not directly usable with std::list

void loadDictionary(Trie& trie, const std::string& dictionaryPath) {
    std::ifstream file(dictionaryPath);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << dictionaryPath << std::endl;
        return;
    }
    std::string word;
    while (getline(file, word)) {
        trie.insert(word);
    }
    std::cout << "Dictionary loaded successfully." << std::endl;
}

void processCommands(Trie& trie, const std::string& inputPath, const std::string& outputPath) {
    std::ifstream inputFile(inputPath);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }
    std::ofstream outputFile(outputPath);
    std::string line;
    bool isFirstOutput = true;  // Flag to manage newlines before any output
    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string command, term;
        ss >> command >> term;

        if (command == "search") {
            bool found = trie.search(term);
            if (!isFirstOutput) outputFile << std::endl;  // Manage newlines correctly
            outputFile << (found ? "true" : "false");
            isFirstOutput = false;
        } else if (command == "prefix") {
            std::list<std::string> resultsList;
            trie.prefixSearch(term, resultsList);
            if (!resultsList.empty()) {
                if (!isFirstOutput) outputFile << std::endl;
                resultsList.sort();  // Use list's member function sort()
                bool first = true;
                for (const auto& result : resultsList) {
                    if (!first) outputFile << " ";
                    outputFile << result;
                    first = false;
                }
                isFirstOutput = false;
            }
        }
    }
    outputFile.close();
}

int main() {
    Trie trie;
    loadDictionary(trie, "../dictionary.txt");
    processCommands(trie, "../input.txt", "../output.txt");
    return 0;
}

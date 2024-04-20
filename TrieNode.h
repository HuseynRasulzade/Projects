#ifndef TRIENODE_H
#define TRIENODE_H
#include "trie.h"

#include <memory>
#include <unordered_map>

class TrieNode {
public:
    bool isEndOfWord;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;

    TrieNode() : isEndOfWord(false) {}
};

#endif //TRIENODE_H

#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <list>
#include <string>

class Trie {
private:
    std::shared_ptr<TrieNode> root;
public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word) const;
    void prefixSearch(const std::string& prefix, std::list<std::string>& results) const;

private:
    void dfs(const std::shared_ptr<TrieNode>& node, const std::string& word, std::list<std::string>& results) const;
};

#endif //TRIE_H

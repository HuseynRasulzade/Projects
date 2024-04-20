#include "trie.h"

Trie::Trie() : root(std::make_shared<TrieNode>()) {}

void Trie::insert(const std::string& word) {
    auto node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            node->children[c] = std::make_shared<TrieNode>();
        }
        node = node->children[c];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const std::string& word) const {
    auto node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            return false;
        }
        node = node->children[c];
    }
    return node->isEndOfWord;
}

void Trie::prefixSearch(const std::string& prefix, std::list<std::string>& results) const {
    auto node = root;
    for (char c : prefix) {
        if (!node->children.count(c)) {
            return; // Prefix not found
        }
        node = node->children[c];
    }
    dfs(node, prefix, results);
}

void Trie::dfs(const std::shared_ptr<TrieNode>& node, const std::string& word, std::list<std::string>& results) const {
    if (node->isEndOfWord) {
        results.push_back(word);
    }
    for (const auto& pair : node->children) {
        dfs(pair.second, word + pair.first, results);
    }
}

#pragma once

#include <string>

const int ALPHABET_SIZE = 26;

class Trie {
private:
    Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;
public:
    Trie() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
    void insert(std::string key);
    bool search(std::string key);
    void remove(std::string key);
};

void Trie::insert(std::string key) {
 
    Trie *pCrawl = &(*this);

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a'; // 0 - 25

        if (!pCrawl->children[index]) // pCrawl->children[index] == NULL 
            pCrawl->children[index] = new Trie();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool Trie::search(std::string key) {
    Trie *pCrawl = &(*this);

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}

Trie* remove(std::string key, int depth = 0) {
    
}
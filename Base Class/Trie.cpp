#pragma once

#include "TrieNode.cpp"
#include <string>

using namespace std;

class Trie {
private:
    TrieNode *root;
    
    /*
        Returns true if parent should delete the mapping
    */
    bool remove(TrieNode *curent, string word, int index) {
        if (index == word.length()) {
            //when end of word is reached only delete if currrent.endOfWord is true.
            if (!curent->isEndOfWord()) {
                return false;
            }

            curent->setEndOfWord(false);

            //if current has no other mapping then return true
            return curent->getChildSize() == 0;
        }

        char ch = word[index];
        TrieNode *node = curent->getValue(ch);
        if (node == nullptr)
            return false;
        
        bool shouldRemoveCurrentNode = remove(node, word, index + 1);

        //if true is returned then delete the mapping of character and trienode reference from map.
        if (shouldRemoveCurrentNode) {
            curent->removeValue(ch);

            //return true if no mappings are left in the map.
            return curent->getChildSize() == 0;
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word);
    bool search(string word);
    void remove(string word);
};

void Trie::insert(string word) {
    TrieNode *current = root;

    for (int i = 0; i < word.length(); i++) {
        char ch = word[i];

        TrieNode *node = current->getValue(ch);
        
        // if key does not exist
        if (node == nullptr) {
            node = new TrieNode();
            current->insertValue(ch, node);
        }
        
        current = node;  
    }

    //mark the current nodes endOfWord as true
    current->setEndOfWord(true);
}

// Returns true if key presents in trie, else false
bool Trie::search(string word) {
    TrieNode *current = root;
    for (int i = 0; i < word.length(); i ++) {
        char ch = word[i];
        TrieNode *node = current->getValue(ch);

        //if node does not exist for given char then return false
        if (node == nullptr)
            return false;
        current = node;
    }

    return current->isEndOfWord();
}

void Trie::remove(string word) {
   remove(root, word, 0); 
}
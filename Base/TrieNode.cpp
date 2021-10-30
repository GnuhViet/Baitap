#pragma once

#include <map>

using namespace std;

class TrieNode {
private:
    // comparator
    struct cmpByAlphabet {
        bool operator()(const char &first,const char &second) {
            return first < second;
        }
    };
    map<char, TrieNode*, cmpByAlphabet> children;
    bool endOfWord;
public:
    TrieNode() {
        endOfWord = false;
    }

    TrieNode(char key) {
        TrieNode *temp = new TrieNode();
        children.insert(pair<char,TrieNode*>(key, temp));
    }

    void removeValue(char key) {
        children.erase(key);
    }

    TrieNode *getValue(char key) {
        /*
        map::operator[k] 
        "If k does not match the key of any element in the container, the function inserts 
        a new element with that key and returns a reference to its mapped value."

        => need to find first
        */
        if (children.find(key) != children.end())
            return children[key];
        else
            return nullptr;
    }

    void insertValue(char key, TrieNode *node) {
        children.insert(pair<char,TrieNode*>(key, node));
    }

    int getChildSize() {
        return children.size();
    }

    void setEndOfWord(bool status) {
        endOfWord = status;
    }

    bool isEndOfWord() {
        return endOfWord;
    }
};
#include "Trie.cpp"
#include <iostream>

using namespace std;

int main() {
    string keys[] = {"the", "a", "abc", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    Trie a;

    for (int i = 0; i < n; i++)
        a.insert(keys[i]);

    a.search("the")? cout << "Yes\n" :
                         cout << "No\n";
    a.remove("the");
    a.search("the")? cout << "Yes\n" :
                         cout << "No\n";

    a.remove("a");
    a.search("a")? cout << "Yes\n" :
                         cout << "No\n";
    a.search("any")? cout << "Yes\n" :
                         cout << "No\n";                                         
    a.search("these")? cout << "Yes\n" :
                           cout << "No\n";
}
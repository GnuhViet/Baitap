
# include "Trie.cpp"
# include <string>
# include <fstream>

#include <iostream>
using namespace std;

class dictionaryRW {
public:
    static void read(Trie *root, string name) {
        string data;
        ifstream infile;

        infile.open(name);
        int size = 0;
        while(!infile.eof()) {
            infile >> data;
            size++;
            root->insert(data);
        }
    }

    static void write(string data, string name) {
        
    }
};


int main() {
    Trie *a = new Trie();
    dictionaryRW::read(a, "words.txt");
    a->search("aah")? cout << "Yes\n" :
                         cout << "No\n";

    a->search("aal")? cout << "Yes\n" :
                           cout << "No\n";
};
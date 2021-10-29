#include "Trie.cpp"
#include <string>
#include <fstream>

class dictionaryRW {
public:
    static void read(Trie dict, string name) {
        string data;
        ifstream infile;
        infile.open(name);
        while(!infile.eof()) {
            infile >> data;
            dict.insert(data);
        }
    }

    static void write(string data, string name) {
        ofstream outfile;
        outfile.open(name, ios::app);
        outfile << '\n' + data;
    }
};
#pragma once

#include "Trie.cpp"

#include <string>
#include <fstream>

using namespace std;

class DictionaryFile {
public:
    static void read(Trie &dict, string name) {
        string data;
        ifstream infile;
        infile.open(name, ios::in);

        if (!infile.is_open())
            throw "file khong ton tai";
        
        while(!infile.eof()) {
            infile >> data;
            dict.insert(data);
        }
    }

    static void write(Trie &dict, string name, string data) {
        dict.insert(data);
        ofstream outfile;
        outfile.open(name, ios::app);
        outfile << '\n' + data;
    }
};
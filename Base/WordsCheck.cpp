#pragma once

#include "Trie.cpp"

#include <vector>
#include <string>

using namespace std;

class WordsCheck{
public:
	static vector<string> check_paragraph(string str, Trie dict){
		vector<string> word;
		int size=0;//do dai tu
		int count=0;//so chu viet hoa 
		string temp;//luu tu tam thoi de cho vao vector

		for (int i = 0 ; i < str.length(); ++i) {
		  	if ( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z' || str[i] == '\'')) {	
				//luu cac tu thuoc A-Z , a-z va '
		  		temp += str[i];
		  		size++;
		  		if (str[i] >= 'A' && str[i] <= 'Z')
		  			count++;
			}
			else {
				//tat ca cac chu viet hoa
				if (count == size)
					if(!dict.search(temp))
						word.push_back(temp);
				
				//co nhieu hon 1 chu viet hoa nhung khong phai tat ca
				else if (count>1 && count<size)
					word.push_back(temp);

				//co 1 chu viet hoa nhung khong phai dau tien
				else if (count==1 && temp[0]>='a' && temp[0]<='z')
					word.push_back(temp);
				
				//co 1 chu viet hoa dau tien hoac khong co chu viet hoa
				else{
					//chuyen chu hoa sang chu thuong
					if (temp[0] >= 'A' && temp[0] <= 'Z')
						temp[0]+=32;
					if(!dict.search(temp))
						word.push_back(temp);
					temp="";
					count=0;
					size=0;
				}
			}
		}
		return word;
	}

};
#pragma once
#include<iostream>
#include "Trie.cpp"
#include<iostream>
#include <vector>
#include <string>

using namespace std;

class WordsCheck{
public:
	/*
		input: paragraph and a dictionary
		output: a vector contains words that could be incorrect
	*/
	static vector<string> check_paragraph(string paragraph, Trie dict){
		paragraph += "."; // for the last else can run
		vector<string> words;
		int size=0;	    //words length
		int count=0;	//number of uppercase letter
		string temp;	//buid the word form A-Z , a-z  or ' in paragraph

		for (int i = 0; i < paragraph.length(); ++i) {
		  	
			// 
			if ( (paragraph[i] >= 'A' && paragraph[i] <= 'Z') || (paragraph[i] >= 'a' && paragraph[i] <= 'z') || paragraph[i] == 39) {	
		  		temp += paragraph[i];
		  		size++;
		  		if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
		  			count++;
			}
			else {
				if (size==0)
					continue;

				//all is uppercase letter
				if (count == size){
					if(!dict.search(temp)){
						words.push_back(temp);
					}
				}

				//more than one uppercase letter
				else if (count > 1 && count < size)
					words.push_back(temp);

				//contains uppercase letter, but not the first one
				else if(count==1 && temp[0]>='a' && temp[0]<='z')
					words.push_back(temp);

				//first letter is uppercase or none at all
				else{
					//to lowwer case
					if(temp[0] >= 'A' && temp[0] <= 'Z')
						temp[0]+=32;
					if(!dict.search(temp))
						words.push_back(temp);
				}
				temp="";
				count=0;
				size=0;
			}
		}
		return words;
	}

};
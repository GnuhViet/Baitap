#include "Trie.cpp"
#include "DictionaryFile.cpp"
#include "WordsCheck.cpp"

#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

class Menu {
private:
    static void pause() {
        cout << "\n Bam phim bat ky de quay lai menu chinh...";
        getch();
    }
public:
    static void Primary(Trie &dict) {
        int choice;
        string fileName;
        bool checkDictionary = false;

        do {
            system("cls");
            cout << "-------------Menu---------------" << endl;
            cout << "  1. Nhap file tu dien" << endl;
            cout << "  2. Nhap doan van" << endl;
            cout << "  3. Tim kiem tu trong tu dien" << endl;
            cout << "  4. exit" << endl;
            cout << "--------------------------------" << endl;
            cout << "  Moi ban nhap lua chon: ";
            cin >> choice;
            cout << "--------------------------------" << endl;
            switch(choice) {
                case 1:
                    {
                        cout << "Nhap ten file: "; cin >> fileName;
                        try {
                            DictionaryFile::read(dict, fileName);
                            checkDictionary = true;
                            cout << "File da duoc doc!";
                        } catch (const char* msg) {
                            cerr << msg << endl;
                        }
                        pause();
                    }
                    break;
                case 2:
                    {
                        if (checkDictionary) {
                            int i;
                            string p;
                            cout << "Nhap doan van can kiem tra: " << endl;
                            fflush(stdin);
                            getline(cin, p);

                            vector<string> incorrect = WordsCheck::check_paragraph(p, dict);
                            vector<string>::iterator it;

                            cout << "--------------------------------" << endl;
                            cout << "Nhung tu co the sai: " << endl;
                            for (it = incorrect.begin(), i = 1; it != incorrect.end(); i++, it++)
                                cout << i << "."<< *it << endl;
                            cout << "--------------------------------" << endl;
                            
                            //aah aahed aahing bahs cal dalii ngusi
                            while(true) {
                                cout << "Chon cac tu muon them vao tu dien (nhap so thu tu), nhap -1 de tro lai menu: ";
                                cin >> i;
                                if (i == -1)
                                    break;
                                i-=1;
                                DictionaryFile::write(dict, fileName, incorrect.at(i));
                                cout << i + 1 << "."<< incorrect.at(i) << " da duoc them vao tu dien" << endl;
                            }

                        }
                        else
                            cout << "Chua co tu dien nao duoc nhap";
                        pause();
                    }
                    break;
                case 3:
                    {   
                        if (checkDictionary) {
                            string words; 
                            cout << "Nhap tu muon tra: "; cin >> words;
                            fflush(stdin); // neu nhap sai (co dau cach se loi), xoa de tranh bi loi
                            if( dict.search(words) )
                                cout << "Tu ton tai\n";
                            else
                                cout << "Tu khong ton tai\n";
                        }
                        else
                            cout << "Chua co tu dien nao duoc nhap";
                        pause();
                    }
                case 4:
                    break;
                default:
                    cout << "Vui long nhan so tu 1 den 4 !" << endl;
                    pause();
            }
        } while (choice != 4);
    }
};

int main() {
    Trie dict;
    Menu::Primary(dict);
}
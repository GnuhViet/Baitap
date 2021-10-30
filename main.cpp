#include "Base/Trie.cpp"
#include "Base/DictionaryFile.cpp"
#include "Base/WordsCheck.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string p1 ="Lunar New Year Festival often falls between late January and early February; it is among the most important holidays in Vietnam. Officially, the festival includes the 1st, 2nd, and 3rd day in Lunar Calendar; however, Vietnamese people often spend nearly a month celebrating this special event. Tet Holiday gets its beginning marked with the first day in the Lunar Year; however, its preparation starts long before that. The 23rd day of the last Lunar month is East Day—a ritual worshiping Kitchen Gods (Tao Cong). It thought that each year on this day, these Gods go to heaven to tell Jade Emperor about all activities of households on earth. On New Year’s Eve, they return home to continue their duties as taking care of families. On New Year’s Day, the first ones who come to visit households—called first-foot—are very important and hence need to be well chosen, as they believed to hold in their hands the entire luck of the family in New Year (Tan Nien). After that, till the third day or even the fourth day of Tet, individuals meet relatives, friends, and colleagues, wishing them all kinds of good things like happiness, health, and success.";
    string p2 ="zopilote zoroaster alacha mothaibabon";
    Trie dict;
    DictionaryFile::read(dict, "words_alpha.txt");

    vector<string> incorrect1 = WordsCheck::check_paragraph(p1, dict);
    vector<string> incorrect2 = WordsCheck::check_paragraph(p2, dict);

    for (auto it = incorrect1.begin(); it != incorrect1.end(); it++)
        cout << *it;
    
    for (auto it = incorrect2.begin(); it != incorrect2.end(); it++)
        cout << *it;
    //
    cout << incorrect1.size() << endl;
    cout << incorrect2.size() << endl;

    dict.search("zulu")? cout << "Yes\n" :
                         cout << "No\n";

    dict.search("zowie")? cout << "Yes\n" :
                         cout << "No\n";

    dict.search("vjppro")? cout << "Yes\n" :
                            cout << "No\n";
}
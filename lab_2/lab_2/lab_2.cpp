﻿/* lab_2.cpp : 
*  by BadDragon at 14.02.2020 in educational purpose
*/

/*Razrabotat' programmu, kotoraya dolzhna sdelat' sleduyushchee:
1.	Prochitat' soderzhimoe tekstovogo fajla. Fajl mozhet soderzhat' :
    a.Slova – sostoyat iz latinskih strochnyh i zaglavnyh bukv, a takzhe cifr, 
    dlinna slova dolzhna byt' ne bolee 20 simvolov
    b.Znaki prepinaniya – «.», «, » «!» « ? » « : » «; »
    c.Probel'nye simvoly – probel, tabulyaciya, simvol novoj stroki.
    2.	Otformatirovat' tekst sleduyushchim obrazom:
    a.Ne dolzhno byt'  probel'nyh simvolov otlichnyh ot probela
    b.Ne dolzhno idti podryad bolee odnogo probela
    c.Mezhdu slovom i znakom prepinaniya ne dolzhno byt' probela
    d.Posle znaka prepinaniya vsegda dolzhen idti probel
    e.Slova dlinoj bolee 10 simvolov zamenyayutsya na slovo «Vau!!!»
    3.	Preobrazovat' poluchennyj tekst v nabor stroka, kazhdaya iz kotoryh soderzhit 
    celoe kolichestvo strok (slovo dolzhno celikom nahodit'sya v stroke) i ee dlinna ne 
    prevyshaet 40 simvolov.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

string readFile(const string& file) {
    ifstream inputFile(file);
    string read, tmp;
    
    while(getline(inputFile, tmp)){
        read += tmp + '\n';
    }

    return read;
}

void replaceSpaces(string &str) {

    for (auto i = str.begin(); i != str.end(); i++) {        

        if (*i == ' ' && *(i + 1) == ' ') {
            
            i = str.erase(i);            
            
        }else if (*i == '\t') {
            i = str.erase(i);
        }
    }
    cout << str << endl;
    //recheck with   
    auto q = unique(str.begin(), str.end(), [](unsigned char l, unsigned char r) {
        return isspace(l) && isspace(r);
    });
    str.erase(q, str.end());
}

void replaceNewline(string &str) {
    for (auto i = str.begin(); i != str.end()-1; i++) {        

        if (*i == '\n') {
            
            i = str.erase(i);            
            
        }
    }
    int i;
}

void restorePunctuation(string& str) {    

    for (auto it = str.begin(); it != str.end() - 1; ++it) {
        if (ispunct(*it) && *(it + 1) != ' ') {
            it = str.insert(it + 1, ' ');
        }
    }

    for (auto it = str.begin()+1; it != str.end(); ++it) {
        if (ispunct(*it) && *(it - 1) == ' ') {
            it = str.erase(it - 1);
        }
    }
}

void replaceWord(string& str) {
    int counter = 0;
    for (auto i = str.begin(); i != str.end();++i, ++counter) {
        
        if (isspace(*i)) {
            if (counter > 10) {
                str.replace(i - counter + 1, i, "vau!!!");
                i = i - counter;                
            }
            counter = 0;
        }        
    }    
}

vector<string> reconfigure(string& str) {
    vector<string> resultVector;
    int pointer = 39;
    int i = 0;
    replaceNewline(str);
    while (str.length() >= 40) {
        auto strIterator = str.begin() + 39;
        if (!isspace(*strIterator)) {
            do {
                strIterator--;
            } while (!ispunct(*strIterator));
            int lastElem = distance(str.begin(), strIterator);
            resultVector.push_back(str.substr(0, lastElem));
            str.erase(0, lastElem);
            strIterator = str.begin();
        } else {
            resultVector.push_back(str.substr(0, distance(str.begin(), strIterator)));
            str.erase(0, distance(str.begin(), strIterator));
            strIterator = str.begin();
        }
        strIterator++;
    }
    if (str.length() != 0) {
        resultVector.push_back(str);
    }
    return resultVector;
}


int main()
{
    string text = readFile("main.cpp");
    cout << text << endl;
    replaceSpaces(text);
    restorePunctuation(text);
    cout << text << endl;
    replaceWord(text);

    cout << text << endl;

    vector<string> result = reconfigure(text);

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << endl;
    }
}


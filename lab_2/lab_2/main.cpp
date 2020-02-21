/* lab_2.cpp : 
*  by BadDragon at 14.02.2020 in educational purpose
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
    for (auto i = str.begin(); i != str.end(); i++) {        

        if (*i == '\n') {
            
            i = str.erase(i);            
            
        }
    }
}

void restorePunctuation(string& str) {    

    for (auto it = str.begin(); it != str.end() - 1; ++it) {
        if (ispunct(*it) && *(it + 1) != ' ') {
            it = str.insert(it + 1, ' ');
        }
    }

    for (auto it = str.begin(); it != str.end(); ++it) {
        if (ispunct(*it) && *(it - 1) == ' ') {
            it = str.erase(it - 1);
        }
    }
    
    /*for (auto i = str.begin()+1; i != str.end(); ++i) {
        if (ispunct(*i) && (!isspace(*i))) {            
            if (isspace(*(i - 1))) i = str.erase(i - 1);           
        }        
    }
    for (auto i = str.begin(); i != str.end(); ++i) {
        if (ispunct(*i) && (!isspace(*i))) {            
            if (!isspace(*(i + 1))) i = str.insert(i + 1, 1, ' ');
        }        
    }*/
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
    while (str.length() > 39) {
        auto strIterator = str.begin() + 39;
        if (!isspace(*strIterator)) {
            strIterator--;
            while (!isspace(*strIterator)) {
                strIterator--;
            }
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
    string text = readFile("lab_2.cpp");
    cout << text << endl;
    replaceSpaces(text);
    //restorePunctuation(text);
    cout << text << endl;
    replaceWord(text);

    cout << text << endl;

    vector<string> result = reconfigure(text);

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << endl;
    }
}


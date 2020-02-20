/* lab_2.cpp : 
*  by BadDragon at 14.02.2020 in educational purpose
*/

//Разработать программу, которая должна сделать следующее :
//1.	Прочитать содержимое текстового файла.Файл может содержать :
//a.Слова – состоят из латинских строчных и заглавных букв, а также цифр, 
//    длинна слова должна быть не более 20 символов
//b.Знаки препинания – «.», «, » «!» « ? » « : » «; »
//c.Пробельные символы – пробел, табуляция, символ новой строки.
//
//2.	Отформатировать текст следующим образом :
//a.Не должно быть  пробельных символов отличных от пробела
//b.Не должно идти подряд более одного пробела
//c.Между словом и знаком препинания не должно быть пробела
//d.После знака препинания всегда должен идти пробел
//e.Слова длиной более 10 символов заменяются на слово «Vau!!!»
//
//3. Преобразовать полученный текст в набор строк, каждая из 
//которых содержит целое количество строк(слово должно целиком находиться в 
//строке) и ее длинна не превышает 40 символов.
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

    for (auto i = str.begin()+1; i != str.end(); ++i) {
        if (ispunct(*i) && (!isspace(*i))) {            
            if (isspace(*(i - 1))) i = str.erase(i - 1);           
        }        
    }
    for (auto i = str.begin(); i != str.end(); ++i) {
        if (ispunct(*i) && (!isspace(*i))) {            
            if (!isspace(*(i + 1))) i = str.insert(i + 1, 1, ' ');
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
    restorePunctuation(text);
    cout << text << endl;
    replaceWord(text);

    cout << text << endl;

    vector<string> result = reconfigure(text);

    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << endl;
    }
}


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void removeNonLetters(string&);
void removeUnecessarySpaces(string&);
void getWords(string&, vector<string>&);
void getVerbs(vector<string>&, vector<string>&);
void showVerbs(vector<string>&);
string copyStringIntoAnotherString(string&, string&, int, int);

int main() {
    string sentence;
    vector<string> verbs;
    vector<string> words;


    cout << "Enter a sentence: ";
    getline(cin, sentence);
    removeNonLetters(sentence);
    removeUnecessarySpaces(sentence);
    getWords(sentence, words);
    getVerbs(words, verbs);
    showVerbs(verbs);
    cout << sentence << endl;
    return 0;
}

void removeNonLetters(string& sentence) {
    for (int i = 0; i < (int) sentence.size(); i++) {
        if (!((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] == ' '))) {
            sentence.erase(sentence.begin() + i);
            i--;
        }
    }
}

void removeUnecessarySpaces(string& sentence) {
    for (int i = 0; i < (int) sentence.size(); i++) {
        if (sentence[i] == ' ' && sentence[i-1] != ' ') {
            continue;
        }
        if (sentence[i] != ' ') {
            continue;
        }
        sentence.erase(sentence.begin() + i);
        i--;
    }
} 

string copyStringIntoAnotherString(string& sentence, string& buffer, int len, int firstCharacter) {
    char tmp[len];    
    sentence.copy(tmp, len, firstCharacter);

    for (int i = 0; i < len; i++) {
        buffer.push_back(tmp[i]); 
    }

    return buffer;
}

void getWords(string& sentence, vector<string>& words) {
    int lastI = 0;
    string wordSave;
    for (int i = 0; i < (int) sentence.size(); i++) {
        if (sentence[i] == ' ') {
            words.push_back(copyStringIntoAnotherString(sentence, wordSave, abs(lastI-i), lastI));
            wordSave.erase();
            lastI = i+1;
        } else if (i == (int) sentence.size()-1) {
            words.push_back(copyStringIntoAnotherString(sentence, wordSave, abs(lastI-i-1), lastI));
            wordSave.erase();
        }
    }
}

void getVerbs(vector<string>& words, vector<string>& verbs) {
    for (int i = 0; i < (int) words.size(); i++) {
        if (words[i][words[i].size()-1] == 'r' || words[i][words[i].size()-1] == 'R') {
            verbs.push_back(words[i]);
        }
    }
}

void showVerbs(vector<string>& verbs) {
    cout << "The verbs identified are here: " << endl;
    for (int i = 0; i < (int) verbs.size(); i++) {
        cout << verbs[i] << endl;
    }
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void removeNonLetters(string&);
void removeUnecessarySpaces(string&);
void getWords(string&, vector<string>&);
void getVerbs(vector<string>&, vector<string>&);
void showVerbs(vector<string>&);


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
    bool firstSpaceFound = false;
    int countSpacesBetweenWords = 0;
    int iStartToDelete;

    for (int i = 0; i < (int) sentence.size(); i++) {
        if (sentence[i] == ' ' && !firstSpaceFound) {
            firstSpaceFound = true;
            iStartToDelete = i;
        }

        if (sentence[i] != ' ' && firstSpaceFound) {

            firstSpaceFound = false;
            sentence.erase(iStartToDelete, countSpacesBetweenWords-1);
            
            countSpacesBetweenWords = 0;
        }

        if (firstSpaceFound && sentence[i] == ' ') {
            countSpacesBetweenWords += 1;
        }
    }
} 

void getWords(string& sentence, vector<string>& words) {
    int firstLetterFound = false;
    string wordSave;
    for (int i = 0; i < (int) sentence.size(); i++) {
        if (sentence[i] != ' ' && !firstLetterFound) {
            firstLetterFound = true;
        }
        if (sentence[i] != ' ' && firstLetterFound) {    
            wordSave.push_back(sentence[i]);
        }

        if (sentence[i] == ' ' && firstLetterFound) {
            firstLetterFound = false;
            words.push_back(wordSave);
            wordSave.erase();
        }
        else if (i == (int) sentence.size()-1) {
            firstLetterFound = false;
            words.push_back(wordSave);
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
#include <iostream>
#include <set>
#include <algorithm>
#include<sstream>
using namespace std;

int main() {
    string word;
    string curr;
    set<string> dict;

    while (cin >> word) {
        curr = "";

        for (int i = 0; i <= word.size(); i++) {
            if(isalpha(word[i]))
                word[i] = tolower(word[i]);
            else
                word[i] = ' ';
        }
        stringstream ss(word);
        while(ss>>curr)
            dict.insert(curr);
    }

    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(std::vector<string> magazine, std::vector<string> note) {
    std::vector<int> countOfWordsMagazine;
    int count;

    for(std::vector<string>::iterator mag=magazine.begin(); mag!=magazine.end(); mag++){
        count = 0;
       for(std::vector<string>::iterator magInner=magazine.begin(); magInner!=magazine.end(); magInner++)
        {   
            if(*mag == *magInner){
                count++;
            }
        }
        countOfWordsMagazine.push_back(count);
    }
    
    for(std::vector<string>::iterator mag=magazine.begin(); mag!=magazine.end(); mag++) { 

        for(std::vector<string>::iterator not1=note.begin(); not1!=note.end(); not1++){
            count = 0;
        
            if(*not1 == *mag){
                count++;    
            }
        }
        
        if(countOfWordsMagazine.front() != count){
            std:: cout << "No" << std::endl;
            exit(1);
        }

        //countOfWordsMagazine.pop_front();
    }

    std::cout << "Yes" << std::endl;
}

int main()
{
    string mn_temp;
    std::string decision;

    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    decision = checkMagazine(magazine, note);

    std::cout << decision << std::endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

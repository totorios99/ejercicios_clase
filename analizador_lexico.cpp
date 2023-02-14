#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_integer(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool is_identifier(string s) {
    if (!isalpha(s[0]))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!isalnum(s[i]))
            return false;
    }
    return true;
}

int main() {
    string line;
    ifstream in_file("input.txt");

    while (getline(in_file, line)) {
        int start = 0;
        int end = 0;
        while (end < line.length()) {
            while (end < line.length() && !isspace(line[end]))
                end++;

            string token = line.substr(start, end - start);
            if (is_integer(token))
                cout << token << " is an integer" << endl;
            else if (is_identifier(token))
                cout << token << " is an identifier" << endl;
            else
                cout << token << " is not recognized" << endl;

            start = ++end;
        }
    }

    return 0;
}


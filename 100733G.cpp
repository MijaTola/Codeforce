#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    stack<char> st;
    cin >> s;
    
    int cur = 1;

    for (char x: s) {
        if(x == '[') cur *= -1;
        if(x == ']') cur *= -1;
        if(x == '(' or x == '[') {
            cout << "(";
            continue;
        }
        if(x == ')' or x == ']') {
            cout << ")";
            continue;
        }

        if(cur == -1) {
            if(x == '*') cout << "+";
            else if(x == '+') cout << "*";
            else if(x >= 'A' and x <= 'Z') cout << (char)tolower(x);
            else if(x >= 'a' and x <= 'z') cout << (char)toupper(x);
        } else {
            cout << x;
        }
    }
    cout << "\n";
    
    return 0;
}


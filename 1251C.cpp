#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        queue<char> a,b;
        for (char x: s) {
            if((x - '0') & 1) a.push(x);
            else b.push(x);
        }
           
        while(!a.empty() and !b.empty()) {
            if(a.front() < b.front()) {
                cout << a.front();
                a.pop();
            } else {
                cout << b.front();
                b.pop();
            }
        }

        while(!a.empty()) {
            cout << a.front();
            a.pop();
        }

        while(!b.empty()) {
            cout << b.front();
            b.pop();
        }
        cout << "\n";
    }
    return 0;
}


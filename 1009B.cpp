#include <bits/stdc++.h>

using namespace std;

string s;
int v[100010];
int b[100010];
int main(){
    memset(v,0,sizeof v);
    cin >> s;

    string ans = "";
    int a = 0;
    for (int i = 0; i < (int)s.size(); ++i) 
        if(s[i] == '1') a++;

    bool first = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '2' and first) {
            while(a) {
                cout << 1;
                a--;
            }
            first = 0;
        }
        if(s[i] != '1')cout <<s[i];
    }
    while(a) {
        cout << 1;
        a--;
    }
    cout << "\n";
    return 0;
}


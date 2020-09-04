#include <bits/stdc++.h>

using namespace std;

int main() {

    
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        bool flag = 1;
        string a = "", b = "";
        for (int i = 0; i < n; ++i) {
            if(flag) {
                if(s[i] == '2')  {
                    a += '1';
                    b += '1';
                } 
                if(s[i] == '0') {
                    a += '0';
                    b += '0';
                } 
                if(s[i] == '1') {
                    a += '1';
                    b += '0';
                    flag = 0;
                }
            } else {
                if(s[i] == '2')  {
                    a += '0';
                    b += '2';
                } 
                if(s[i] == '0') {
                    a += '0';
                    b += '0';
                } 
                if(s[i] == '1') {
                    a += '0';
                    b += '1';
                    flag = 0;
                }
            }
        }
        cout << a << "\n";
        cout << b << "\n";
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

string s;
int sz;
int a[28];
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0,sizeof a);
        cin >> s;
        for (int i = 0; i < s.size(); ++i) 
            a[s[i] - 'a']++;
        
        string x = "";
        for (int i = 0; i < 27; ++i)
            if(a[i]) x += (char) (i + 'a');
        s = x;
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                if(abs(s[i] - s[j]) != 1) 
                    swap(s[i + 1], s[j]);
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if(abs(s[i] - s[j]) != 1) {
                    swap(s[i - 1], s[j]);
                    break;
                }
            }
        }

        bool flag = 1;
        for (int i = 0; i < s.size() - 1; ++i) 
            flag &= (abs(s[i] - s[i + 1]) != 1);

        if(flag) {
            for (char p: s)
                while(a[p - 'a']) {
                    a[p - 'a']--;
                    cout << p;
                }
            cout << "\n";
        } else cout << "No answer\n";
        
    }
    return 0;
}


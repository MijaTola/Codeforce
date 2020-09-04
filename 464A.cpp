#include <bits/stdc++.h>

using namespace std;

int n,p;
string s;

bool ver(string &r) {
    string t = "";
    for (int i = r.size() - 1; i >= 0; i--) {
        if(r[i] == r[i + 1] ) return 0;
        if(i + 3 <= (int)r.size()) {
            string a = "";
            a = a + r[i] + r[i + 1] + r[i + 2];
            string b = "";
            b = b + r[i + 2] + r[i + 1] + r[i];
            if(a == b) return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> p;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        string r = s;
        for (int j = s[i] - 'a' + 1; j < p; ++j) {
           r[i] = (char) (j + 'a');
           if(s.size() == 1) {
            cout << r << "\n";
            return 0;
           }
           for (int k = i + 1; k < (int)s.size(); ++k) {
                for (char l = 'a'; l <= p + 'a'; ++l) {
                    if(r[k - 1] != l) {
                        string a = "";
                        a = a + r[k - 2] + r[k - 1] + l;
                        string b = "";
                        b = b + l + r[k - 1] + r[k - 2];
                        if(a == b) continue;
                        r[k] = l;
                        break;
                    }
                
                }
           }
           if(ver(r)) {
                return cout << r << "\n",0;
           }
        }
    }
    puts("NO");
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,int> > v;
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '.') cur++;
        else {

            int m1 = cur / 2;
            int m2 = cur - m1;
            if(a > b) {
                m2 = min(a,m2);
                m1 = min(b,m1);
                a -= m2;
                b -= m1;
            } else {
                m2 = min(b,m2);
                m1 = min(a,m1);
                a -= m1;
                b -= m2;
            }
            ans += m1 + m2;
            cur = 0;
        }
    }

    int m1 = cur / 2;
    int m2 = cur - m1;
    if(a > b) {
        m2 = min(a,m2);
        m1 = min(b,m1);
        a -= m2;
        b -= m1;
    } else {
        m2 = min(b,m2);
        m1 = min(a,m1);
        a -= m1;
        b -= m2;
    }
    ans += m1 + m2;
    cur = 0;
    cout << ans << "\n";

    return 0;
}

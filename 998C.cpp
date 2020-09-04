#include <bits/stdc++.h>

using namespace std;

long long n,x,y; 
string s;
int pre[300010];
int pre2[300010];
int main(){
    cin >> n >> x >> y >> s;
    swap(x,y);
    long long ans1 = 0, ans2 = 0, ans3 = 0;
    int cnt = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0') cnt++, total++;
        else {
            if(cnt) ans1 += x;
            cnt = 0;
        }
    }
    if(!total) return cout << "0\n",0;
    if(cnt) ans1 += x;
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0') cnt++;
        pre[i] = cnt;
    }

    cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') cnt++;
        pre2[i] = cnt;
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0') cnt++;
        else {
            if(cnt and pre2[i])ans2 += y;
            cnt = 0;
        }
    }

    ans2 += x;
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') cnt++;
        else {
            if(cnt and pre[i]) ans3 += y;
            cnt = 0;
        }
    }
    ans3 += x;
    cout << min(ans3, min(ans2, ans1)) << "\n";
    return 0;
}

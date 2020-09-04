#include <bits/stdc++.h>

using namespace std;

int a[30];
unordered_map<string,int> mp1;
unordered_map<string,int> mp2;

string get(char c) {
    stringstream ss;
    string str;
    ss << c;
    ss >> str;
    return str;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int p = 0;
    for (int i = 0; i <n ; ++i) {
        string s; cin >> s;
        memset(a, 0,sizeof a);

        for (int i = 0; i < (int)s.size(); ++i) 
            a[s[i] - 'a']++;

        string h = ""; 
        string e = "";

        int flag = 0;
        bool even = 0;
        bool zero = 0;
        for (int i = 0; i < 30; ++i) {
            if(a[i] & 1) {
                h += (char)(i + 'a');
                flag++;
            } else if(a[i] > 0){
                e += (char)(i + 'a');
                even = 1;
            }
            if(a[i] > 0) zero = 1;
        }
        if(flag > 0) { 
            if(flag == 1 and even) {
                mp2[e]++;            
            }
            mp1[h]++;
        }
        if(zero and !flag) {
            mp2[e]++;
            p++;
        }
    }

    long long ans = mp2.size() * (mp2.size() - 1) / 2;
    vector<string> t;
    for (pair<string,int> p: mp1) {
        int pp = p.second;
        string ss = p.first;
        if(ss.size() == 2) {
            string x = get(ss[0]);
            string y = get(ss[1]);
            cout << ss << "\n";
            cout << mp1[x] << " " << mp1[y] << "\n";
            int val = 0;
            val = mp1[x] + 1;
            ans += val * (val - 1) / 2;
            val = mp1[y] + 1;
            ans += val * (val - 1) / 2;
        }
        ans += pp * (pp - 1) / 2;
    }

    for (pair<string,int> p: mp2) {
        int pp = p.second;
        ans += pp * (pp - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}


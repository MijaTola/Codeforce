#include <bits/stdc++.h>

using namespace std;

int n,k;
string val[] = { "1110111", "0010010", "1011101", "1011011",
    "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
map<string,int> mp;
vector<string> v;

//a -> b
bool check (string a, string b) {
    for (int i = 0; i < (int)a.size(); ++i) {
        if(a[i] == '1' and b[i] == '0') return 0;
    }
    return 1;
}

int get(string a, string b) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if(b[i] == '1' and a[i] == '0') ans++;

    }
    return ans;
}

int dp[2010][2010];

int f(int pos, int dk) {
    if(pos == n)  return dk == 0;
    

    int &ans = dp[pos][dk];
    if(ans != -1) return ans;
    ans = 0;

    for (int i = 9; i >= 0; i--) {
        if(check(v[pos], val[i]) ){
            if(dk - get(v[pos], val[i]) >= 0) 
                ans |= max(ans, f(pos + 1, dk - get(v[pos], val[i])));          
        }
    }
    return ans;
}

string res = "";
void r(int pos, int dk) {
    if(dk < 0) return;
    if(pos == n) {
        return;
    }

    for (int i = 9; i >= 0; i--) {
        if(check(v[pos], val[i]) ){
            if(f(pos + 1, dk - get(v[pos], val[i]))) {
                res += (char)(i + '0');
                r(pos + 1, dk - get(v[pos], val[i]));
                break;
            }
        }
    }
    return ;
}

int main() {

    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)  {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    if(!f(0, k))  return cout << -1 << "\n",0;

    r(0,k);

    while((int)res.size() != n) res = "0" + res;
    cout << res << "\n";
    

    return 0;
}


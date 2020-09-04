#include <bits/stdc++.h>

using namespace std;

string large = "";

string sum(string a, string b) {
    if(a == "0" or b == "0") 
        return large;
    
    string ans = "";
    int last = 0;
    int i = a.size() - 1, j = b.size() - 1;
    for (; i >= 0 and j >= 0; i--,j--) {
        int da = a[i] - '0';
        int db = b[j] - '0';
        int c = da + db + last;
        last = c / 10;
        ans += (char)((c % 10) + '0');
    }
    while(i >= 0) {
        int c = (a[i] - '0') + last;
        ans += (char)((c % 10) + '0');
        last = c / 10;
        i--;
    }

    while(j >= 0) {
        int c = (b[j] - '0') + last;
        ans += (char)((c % 10) + '0');
        last = c / 10;
        j--;
    }
    if(last) ans += (char) (last + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string mn(string a, string b) {
    if((int)a.size() < (int)b.size()) return a;
    if((int)a.size() > (int)b.size()) return b;
    if(a < b) return a;
    return b;
}
int main() {
        
    string s;
    int n;
    cin >> n >> s;

    int mid = n / 2;
    string ans = "", ans1 = "", ans2 ="", ans3 = "";
    for (int i = 0; i < 1000000; ++i) {
        ans += "9";
        ans1 += "9";
        ans2 += "9";
        ans3 += "9";
        large += "9";
    }
    while(s[mid] == '0' and mid < n - 1) mid++;
    ans = sum(s.substr(0,mid), s.substr(mid,n));
    if(mid + 1 < n) ans1 = sum(s.substr(0,mid + 1), s.substr(mid + 1,n));
    mid = n / 2;
    while(s[mid] == '0' and mid > 1) mid--;
    if(mid >= 0 and s[mid] != '0') ans2 = sum(s.substr(0,mid), s.substr(mid,n));
    if(mid - 1 > 0) ans3 = sum(s.substr(0,mid - 1), s.substr(mid - 1,n));
    cout << mn(ans, mn(ans1, mn(ans2, ans3))) << "\n";
    return 0;
}


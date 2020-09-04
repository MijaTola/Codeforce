#include <bits/stdc++.h>

using namespace std;

bool operator < (string a, string b)
{
    if (a.size() < b.size()) return true;
    if (b.size() < a.size()) return false;

    for (int i = 0;i < a.size();i++)
    {
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }
    return true;
}
int main(){
	string n; cin >> n;
	string b = "127";
    string s = "32767";
    string i = "2147483647";
    string l = "9223372036854775807";

    if (n < b) cout << "byte";
    else if (n < s) cout << "short";
    else if (n < i) cout << "int";
    else if (n < l) cout << "long";
    else cout << "BigInteger";

	return 0;
}
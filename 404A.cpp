#include <bits/stdc++.h>

using namespace std;
char m[305][305];
int n;
bool verify()
{
    char c = m[0][1], d = m[0][0];
    if (c == d) return false;
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i ==j || i + j == n-1) {
                if(d != m[i][j]) return false;
            }else {
                if(c != m[i][j]) return false;
            }
        }
    }
    return true;
}
int main(){

	char x;

	set<int> p;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> x;	
			m[i][j] = x;
		}

	if(verify()) cout << "YES" << endl;
	else cout <<"NO" << endl;
	return 0;
}
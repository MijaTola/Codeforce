#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
    a--;
    cout << (((a + b) % n) + n) % n + 1 << "\n";
	return 0;
}

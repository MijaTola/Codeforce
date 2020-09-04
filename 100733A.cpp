#include <bits/stdc++.h>
 
using namespace std;
 
int main() {

    long double n,a,b;
    cin >> n >> a >> b;
    cout.precision(10);
    cout<< fixed << n * a * b * sin(acos(-1)/n) << "\n";
	return 0;
}


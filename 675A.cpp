#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(c == 0) return puts(a == b? "YES": "NO"),0;
    int dis = b - a;
    if(dis % c == 0 and dis / c >= 0) puts("YES");
    else puts("NO");
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    if(a == 1 or b == 1 or c == 1 or (a == b and b == c and c == 3)) return puts("YES"),0;
    if((a == b and b == 2) or (a == c and c == 2) or (b == c and c == 2))
        return puts("YES"),0;

    if((a == b and b == 4 and c == 2) or (a == c and c == 4 and b == 2) or (b == c and c == 4 and a == 2)) return puts("YES"),0;
    puts("NO");
}


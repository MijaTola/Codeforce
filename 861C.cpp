
#include <bits/stdc++.h>

using namespace std;

char s[3010];
int sz;

bool ver(char a){
    return a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u';
}

bool ver2(char a, char b, char c){
    return a != b or a != c or b != c;
}

void f(int pos){
    if(pos >= sz) return;
    if(!ver(s[pos]) and !ver(s[pos + 1]) and !ver(s[pos + 2]) and ver2(s[pos],s[pos + 1], s[pos + 2])){
        if(pos < sz) printf("%c",s[pos]);
        if(pos + 1 < sz) printf("%c ",s[pos + 1]);
        f(pos + 2);
        return;
    }
    
    if(pos < sz)printf("%c", s[pos]);
    f(pos + 1);
}
int main(){
    scanf("%s",s);  
    sz = strlen(s);
    f(0);
    puts("");
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

char s[110];
int cur[3],p[3],need[3];
long long make[3];
long long t;

bool ver(long long c){
    long long money = 0;
    for (int i = 0; i < 3; ++i){
        make[i] = c*need[i];
        if(make[i] > cur[i]){
            make[i] = abs(make[i] - cur[i]);
            money += make[i] * p[i];
        }
    }
    return t >= money;
}
int main(){
    scanf("%s",s);
    int sz = strlen(s);
    scanf("%d %d %d",&cur[0],&cur[1],&cur[2]);
    scanf("%d %d %d %lld",&p[0],&p[1],&p[2],&t);
    for (int i = 0; i < sz; ++i){
        if(s[i] == 'B') need[0]++;
        else if(s[i] == 'S') need[1]++;
        else need[2]++;
    }

    
    long long a = 0, b = 1e15;

    while(b - a > 1LL){
        long long mid = (a + b) / 2LL;
        if(ver(mid)) a = mid;
        else b = mid;
    }

    printf("%lld\n",a); 
}


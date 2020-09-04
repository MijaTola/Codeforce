#include <bits/stdc++.h>

using namespace std;

int n, x;
int v[3];
bool is[500010];
vector<int> prime;
void criba() {
    for (int i = 2; i * i < 500010; ++i) {
        if(is[i]) continue;
        for (int j = i + i; j < 500010; j +=i) 
            is[j] = 1;
    }

    for (int i = 2; i < 200010; ++i)
        if(!is[i]) prime.push_back(i);
}

int main() {
    criba();
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        v[x]++;
    }
    
    int pos = 0;
    int sum = 0;
    while(pos < prime.size() and (v[2] or v[1])) {
        while(sum + 2 <= prime[pos] and v[2]) {
            sum += 2,v[2]--;
            printf("2 ");
        }

        while(sum + 1 <= prime[pos] and v[1]) {
            sum++, v[1]--;
            printf("1 ");
        }
        pos++;
    }

    while(v[2]--) printf("2 "); 
    while(v[1]--) printf("1 ");
    puts("");
    return 0;
}


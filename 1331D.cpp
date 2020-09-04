#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
int sieve[1100];

int main(){
	memset(sieve,false,sizeof sieve);	
	
	for (int i = 2; i*i < 1100; ++i){
		int c = i + i;
		while(c < 1100){
			sieve[c] = true;
			c += i;
		}
	}

	for (int i = 2; i < 1100; ++i)
		if(!sieve[i])	primes.push_back(i);

	
	int n; 
    cin >> n;
    for (int x: primes) {
        for (int y: primes) {
            if(x * y == n) {
                int xx = min(x,y);
                int yy = max(x,y);
                cout << xx << yy << "\n";
                return 0;
            }
        }
    }
	return 0;
}

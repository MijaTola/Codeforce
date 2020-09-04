#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100000

bool dragons[MAX];
int d;
void fill(int i){
	int c = i;
	while(c <= d){
		dragons[c] = true;
		c+=i;
	}

}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int k,l,m,n;
	cin >> k >> l >> m >> n >> d;
	fill(k);
	fill(l);
	fill(m);
	fill(n);
	int c = 0;

	for (int i = 1; i <= d; ++i)
		if(dragons[i]) c++;
	cout << c << endl;
	return 0;	
}
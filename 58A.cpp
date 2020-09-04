#include <iostream> 

using namespace std;

int main(){
	string hello = "hello";
	string x;

	cin >> x;

	string ans = "";
	int c = 0;
	for (int i = 0; i < x.size(); ++i)
	{
		if(c > 4) break;
		if(x[i] == hello[c]){
			ans+=x[i];
			c++;
		}
	}
	if(ans == hello) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
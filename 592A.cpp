#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

bool black[8];
bool white[8];
map<int,int> mb;
map<int,int> mw;
int main(){
	queue<pair<int,int> > w;
	queue<pair<int,int> > b;
	for (int i = 0; i < 8; ++i)
	{
		mb[i] = 9999;
	}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j){
			char x;
			cin >> x;
			if(x == 'W'){
				w.push(make_pair(i,j));
				white[j] = true;	
				int z = mw[j];
				if(i > z) mw[j] = i;
			}else if(x == 'B'){
				b.push(make_pair(i,j));
				black[j] = true;
				int z = mb[j];
				if(i < z) mb[j] = i;
			}
		}
	int minW = 99999;
	int minB = 99999;
	while(!w.empty()){
		int x = w.front().first;
		int y = w.front().second;
		//cout << mb[y] << " " <<y << endl;
		if(black[y] && mb[y] < x){
			w.pop();
			continue;
		}
 		minW = min(x,minW);
 		w.pop();
	}
	while(!b.empty()){
		int x = b.front().first;
		int y = b.front().second;
		if(white[y] && mw[y] > x){
			b.pop();
			continue;
		}
		minB = min(7-x,minB);
		b.pop();
	}
	//cout << minW << " " << minB << endl;
	if(minB < minW) cout << "B" << endl;
	else if(minB > minW) cout << "A" << endl;
	else if(minB == minW) cout << "A" << endl;
}
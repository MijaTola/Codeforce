#include <iostream>

using namespace std;

bool ver(int x) {
  int sum = 0;
  while(x) {
    sum += x%10;
    x/=10;
  }
  return sum % 4 == 0;
}
int main() {
  int n;
  cin >> n;
  int r = n;
  int l = n;
  while(!ver(r)) r++;
  while(!ver(l)) l--;

  if(abs(l - n) < abs(l - n)) cout << l << "\n";
  else cout << r<< "\n";
  return 0;
}

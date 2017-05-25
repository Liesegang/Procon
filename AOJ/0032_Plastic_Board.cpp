#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int a, b, c;
  char t;
  int r = 0, d = 0;
  while(cin >> a >> t >> b >> t >> c){
   if(a * a + b * b == c * c)
     r++;
   if(a == b)
     d++;
  }
  cout << r << endl << d << endl;
  return 0;
}

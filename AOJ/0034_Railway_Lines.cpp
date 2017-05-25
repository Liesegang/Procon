#include <iostream>
using namespace std;

int main(){
  int l[10], v1, v2;
  int sum;
  char t;
  while(cin >> l[0]){
    for(int i = 1; i < 10; ++i){
      cin >> t;
      cin >> l[i];
    }
    sum = 0;

    cin >> t >> v1 >> t >>  v2;
    for(int i = 0; i < 10; ++i){
      sum += l[i];
    }

    double cross = sum * v1 / double(v1 + v2);

    int part_sum = 0;
    for(int i = 0; i < 10; i++){
      part_sum += l[i];
      if(cross <= part_sum){
        cout << (i + 1) << endl;
        break;
      }
    }
  }
}

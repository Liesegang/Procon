#include <iostream>
using namespace std;

int main(){
  int w = 0;
  while(cin >> w){
    bool first = true;
    for(int i = 0; i < 10; i++){
      if(w & (1 << i)){
        if(!first){
          cout << " ";
        } else {
          first = false;
        }
        cout << (1 << i);
      }
    }
    cout << endl;
  }
}


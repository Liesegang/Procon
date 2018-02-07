#include <iostream>
using namespace std;

int main(){
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  int N, M;
  char d;
  while(1){
    bool range[21][21] = {{}};
    cin >> N;
    if(!N)
      break;
    for(int i = 0; i < N; ++i){
      int x, y;
      cin >> x >> y;
      range[x][y] = true;
    }

    cin >> M;
    int robot_x = 10, robot_y = 10, n = 0;
    for(int i = 0; i < M; i++){
      int dir, length;
      cin >> d >> length;
      switch(d){
        case 'E':
          dir = 0;
          break;
        case 'N':
          dir = 1;
          break;
        case 'W':
          dir = 2;
          break;
        case 'S':
          dir = 3;
          break;
      }

      for(int j = 0; j < length; ++j){
        robot_x += dx[dir];
        robot_y += dy[dir];
        n += range[robot_x][robot_y];
        range[robot_x][robot_y] = false;
      }
    }

    cout << (n == N ? "Yes" : "No") << endl;
  }
}

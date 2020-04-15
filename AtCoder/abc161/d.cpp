#include <bits/stdc++.h>
using namespace std;
 
// Type alias
using ll=long long;
using ld=double;
using innt=long long;
 
// Macro
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl
 
#define ALL(a) a.begin(),a.end()
 

ll memo[40][10] = {};

int count_zero(int keta, int start){
  if(keta == 1){
    return 1;
  }

  if(memo[keta][start])
    return memo[keta][start];

  if(keta == 2 && (start == 0 || start == 9)){
    memo[2][0] = 2;
    memo[2][9] = 2;
    return 2;
  }
  if(keta == 2){
    memo[2][1] = 3;
    memo[2][2] = 3;
    memo[2][3] = 3;
    memo[2][4] = 3;
    memo[2][5] = 3;
    memo[2][6] = 3;
    memo[2][7] = 3;
    memo[2][8] = 3;
    return 3;
  }

  if(start == 0){
    memo[keta][start] = count_zero(keta - 1, 0) + count_zero(keta - 1, 1);
    return memo[keta][start];
  }
  if(start == 9){
    memo[keta][start] = count_zero(keta - 1, 8) + count_zero(keta - 1, 9);
    return memo[keta][start];
  }

  memo[keta][start] = count_zero(keta - 1, start - 1) + count_zero(keta - 1, start) + count_zero(keta - 1, start + 1);
  return memo[keta][start];
} 
 
int count(int keta){
  if(keta == 1){
    return 10;
  }

  int res = 0;
  REP(i, 1, 9){
    res += count_zero(keta - 1, i-1) + count_zero(keta - 1, i) + count_zero(keta - 1, i+1);
  }
  res += count_zero(keta - 1, 8);
  res += count_zero(keta - 1, 9);
  return res;
}

void kazu_zero(int keta, int mae, int t){
  //cout << "kazu_zero(" << keta << "," << mae << "," << t << ");" << endl;
  if(keta == 1 && mae == 0){
    cout << mae + t;
    return;
  }

  if(keta == 1){
    cout << mae + t - 1;
    return;
  }

  int i = mae - 1;
  while(true){
    if(i < 0 || i > 9){
      i++;
      continue;
    }

    int u = count_zero(keta, i);
    if(t - u < 0){
      cout << i;
      break;
    }

    t -= u;
    i++;
  }

  kazu_zero(keta - 1, i, t);
  return;
}

void kazu(int keta, int t){
  //cout << "kazu(" << keta << "," << t << ");" << endl;
  if(keta == 1){
    cout << t;
    return;
  }
  
  int i = 1;
  while(true){
    int u = count_zero(keta, i);
    if(t - u < 0){
      cout << i;
      break;
    }
    t -= u;
    i++;
  }

  kazu_zero(keta - 1, i, t);
  return;
}

void solve(){
  int K;
  cin >> K;

  int keta = 1;
  while(true){
    int t = count(keta);
    if(K - t < 0){
      break;
    }else{
      K -= t;
    }
    keta++;
  }
  //cout << keta << "," << K << endl;

  kazu(keta, K);
  cout << endl;
}
 
int main(){
  // FastIO
  //ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}




















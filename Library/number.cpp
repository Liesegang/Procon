// エラトステネスの篩
// 素数列挙

vector<int> Eratosthenes(const int N){
  vector<bool> is_prime(N + 1);
  for(int i = 0; i <= N; i++) is_prime[i] = true;
  vector<int> P;
  for(int i = 2; i <= N; i++){
    if(is_prime[i]){
      for(int j = 2 * i; j <= N; j += i) is_prime[j] = false;
      P.emplace_back(i);
    }
  }
  return P;
}


// 素数判定
bool IsPrime(ll num){
  if(num < 2) return false;
  if(num == 2) return true;
  if(num % 2 == 0) return false;

  double sqrtNum = sqrt(num);
  for(ll i = 3; i <= sqrtNum; i += 2) if(num % i == 0) return false;
  return true;
}


// 素因数分解
map<ll, int> PrimeFactor(ll n) {
  map<ll, int> ret;

  while(n % 2 == 0){
    ret[2]++;
    n /= 2;
  }

  double sqrtNum = sqrt(num);
  for(ll i = 3; i <= sqrtNum; i += 2){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
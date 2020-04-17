// エラトステネスの篩
// 素数列挙

std::vector<int> Eratosthenes(const int N){
  std::vector<bool> is_prime(N + 1);
  for(int i = 0; i <= N; i++) is_prime[i] = true;
  std::vector<int> P;
  for(int i = 2; i <= N; i++){
    if(is_prime[i]){
      for(int j = 2 * i; j <= N; j += i) is_prime[j] = false;
      P.emplace_back(i);
    }
  }
  return P;
}


// 素数判定
bool IsPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) if (num % i == 0) return false;
  return true;
}


// 素因数分解
map< ll, int > PrimeFactor(ll n) {
  map< ll, int > ret;
  for(ll i = 2; i * i <= n; i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
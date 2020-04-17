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
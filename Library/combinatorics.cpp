ll ncm(ll n, ll m, ll mod){
  ll ans = 1;
  rep(i, m){
    ans *= (n-i);
    ans %= mod;
    ans *= pow(i+1, mod - 2, mod);
    ans %= mod;
  }
  return ans;
}
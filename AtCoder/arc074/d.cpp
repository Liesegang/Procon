#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;
const ll neg_inf = numeric_limits<ll>::min() / 2;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
    const ll MAX_N=1e5 + 5;
    ll N, a[MAX_N * 3] ={};
    ll before_score[MAX_N] = {}, after_score[MAX_N] = {};
    priority_queue<ll, vector<ll>, greater<ll> > before;
    priority_queue<ll, vector<ll>, less<ll> >    after;

    cin >> N;
    rep(i,3*N) cin >> a[i];


    ll before_sum = 0, after_sum = 0;
    rep(i,N){ before_sum += a[i]; before.push(a[i]); }
    REP(i, 2*N, 3*N){ after_sum += a[i]; after.push(a[i]); }


    rep(k,N+1){
        before_score[k] = before_sum;
        before.push(a[N+k]);
        before_sum += a[N+k] - before.top(); before.pop(); 
    }

    rep(k,N+1){
        after_score[k] = after_sum;
        after.push(a[2*N-k-1]);
        after_sum += a[2*N-k-1] - after.top(); after.pop(); 
    }


    ll ret = neg_inf;
    rep(i, N+1){
        ll val;
        val = before_score[i] - after_score[N-i];
        ret = max(ret, val);
    }

    cout << ret << endl;
}

int main(){
    solve();
    return 0;
}
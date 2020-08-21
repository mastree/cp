#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e6 + 10;

bitset<N> sieve;
vector<int> prime;
int n, k;

void init(){
    prime.pb(0);
    sieve[1] = 1;
    for (int i=2;i * i<N;i++){
        if (sieve[i]) continue;
        for (int j=i * i;j<N;j+=i){
            sieve[j] = 1;
        }
    }
    for (int i=1;i<N;i++){
        if (!sieve[i]) prime.pb(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> k;
    for (int i=1;i<=(n - 1) * k + 1;i+=k){
        cout << prime[i] << el;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long MOD = 1e9 + 7;

long long dp[N], size[N], _count[N];
long long factorial[N];

int n;
vector <int> adjList[N]; // adjacency list

void setup(){
    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    factorial[0] = 1;
    for (long long i=1;i<=n;i++){
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

long long fpow(long long a, long long b){
    if (b == 0) return 1;
    long long temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

long long inv(long long a){ // inverse modulo
    return fpow(a, MOD - 2);
}

void solve_size(int i, int parent){
    size[i] = 1;
    for (auto j : adjList[i]){
        if (j == parent) continue;
        solve_size(j, i);
        size[i] += size[j];
    }
}

void solve_dp(int i, int parent){
    if (size[i] == 1){ // Basis
        dp[i] = 1;
        return;
    }
    dp[i] = factorial[size[i] - 1];
    for (auto j : adjList[i]){ // iterasi semua tetangga simpul i
        if (j == parent) continue;
        solve_dp(j, i);
        dp[i] = (dp[i] * dp[j] % MOD) * inv(factorial[size[j]]) % MOD;
    }
}

void solve_count(int i, int parent){
    if (i == parent){ // Akar
        _count[i] = dp[i];
    } else{
        _count[i] = (_count[parent] * factorial[size[i]] % MOD) * inv((n - size[i]) * dp[i] % MOD) % MOD;
        for (auto j : adjList[i]){ // iterasi semua tetangga simpul i
            if (j == parent) continue;
            _count[i] = (_count[i] * dp[j] % MOD) * inv(factorial[size[j]]) % MOD;
        }
    }
    for (auto j : adjList[i]){
        if (j == parent) continue;
        solve_count(j, i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    setup();

    // akar = 1
    solve_size(1, 1);
    solve_dp(1, 1);
    solve_count(1, 1);

    long long result = 0;
    for (int i=1;i<=n;i++){
        cout << "count(" << i << ") = " << _count[i] << endl;
        result += _count[i];
    }
    cout << "result = " << result << endl;

    return 0;
}
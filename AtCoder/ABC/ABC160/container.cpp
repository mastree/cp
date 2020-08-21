void solve_dp(int i, int parent){
    if (size[i] == 1){ // Basis
        dp[i] = 1;
        return;
    }
    dp[i] = factorial[size[i] - 1];
    for (auto j : adjList[i]){ // iterasi semua tetangga simpul i
        if (j == parent) continue;
        solve_dp(j, i);
        dp[i] = (dp[i] * dp[j]) / factorial[size[j]];
    }
}

long long solve_count(int i, int parent){
    if (parent == -1){ // Akar
        _count[i] = dp[i];
    } else{
        _count[i] = (_count[parent] * factorial[size[i]]) / ((n - size[i]) * dp[i]);
        for (auto j : adjList[i]){ // iterasi semua tetangga simpul i
            if (j == parent) continue;
            _count[i] = (_count[i] * dp[j]) / factorial[size[j]];
        }
    }
    long long result = _count[i];
    for (auto j : adjList[i]){
        if (j == parent) continue;
        result += solve_count(j, i);
    }
    return result;
}
#include <bits/stdc++.h>

int hitung(const vector<vector<int>>& vec, int ra, int ca, int rb, int cb){
    return vec[rb][cb] - vec[ra - 1][cb] - vec[rb][ca - 1] + vec[ra - 1][ca - 1];
}

bool bisa(const vector<vector<int>>& vec, int n, int m, int k){
    for (int i=1;i + k * 2 - 1<=n;i++){
        for (int j=1;j + k * 2 - 1<=m;j++){
            if (hitung(vec, i, j, i + k * 2 - 1, j + k - 1) + hitung(vec, i + k, j + k, i + k * 2 - 1, j + k * 2 - 1) == k * k * 3) return 1;
        }
    }
    return 0;
}

int solution(vector< vector<bool> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i=1;i<=n;i++){
        int cur = 0;
        for (int j=1;j<=m;j++){
            cur += A[i - 1][j - 1];
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    int l = 0, r = min(n, m) / 2;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (bisa(pre, n, m, mid)){
            l = mid;
        } else{
            r = mid - 1;
        }
    }
    return l;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = (1 << 18);
const int LL = ceil(log2(N)) + 2;

int n;
int a[N], b[N];
int pre[K];
int sp[K][LL];
long long pref[N], suff[N];
long long L[N], R[N];

int get(int l, int r) {
    int k = pre[r - l + 1];
    return max(sp[l][k], sp[r - (1 << k) + 1][k]);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 2; i < K; i++) {
        pre[i] = pre[i >> 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        sp[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid, i) > a[i]) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == -1) continue;
        pref[i] = (1LL) * b[at] + pref[at];
    }
    for (int i = n; i >= 1; i--) {
        int l = i + 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(i, mid) > a[i]) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) continue;
        suff[i] = (1LL) * b[at] + suff[at];
    }
    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (last != -1) {
            L[i] = (1LL) * b[last] + pref[last];
        }
        if (i < n && a[i] > a[i + 1]) {
            last = i;
        }
    }
    last = -1;
    for (int i = n; i >= 1; i--) {
        if (last != -1) {
            R[i] = (1LL) * b[last] + suff[last];
        }
        if (i > 1 && a[i] > a[i - 1]) {
            last = i;
        }
    }
    long long maks = 0;
    for (int i = 1; i <= n; i++) {
        maks = max(maks, L[i] + R[i]);
    }
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        if (L[i] + R[i] == maks) {
            pos.emplace_back(i);
        }
    }
    int len = pos.size();
    for (int i = 0; i < len; i++) {
        cout << pos[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}
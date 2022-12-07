#include <bits/stdc++.h>

using namespace std;

void dismiss() {
    assert(false);
    cout << "Invalid Input\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v;
    {
        int x;
        while (cin >> x) {
            v.emplace_back(x);
            if (x < 0 || 1000 < x) dismiss();
        }
    }
    int n = v.size();
    if (n > 50) dismiss();
    sort(v.rbegin(), v.rend());
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         for (int k = i + 1; k < n; k++) {
    //             // vector<int> cur = {v[i], v[j], v[k]};
    //             // sort(cur.rbegin(), cur.rend());
    //             if (v[j] == v[i] + v[k] + 10) {
    //                 cout << v[j] << " " << v[i] << " " << v[k] << '\n';
    //             }
    //         }
    //     }
    // }
    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            for (int k = 0; k < j; k++) {
                if (v[k] == v[j] + v[i] + 10) {
                    cout << v[k] << " " << v[j] << " " << v[i] << '\n';
                }
            }
        }
    }
    
    return 0;
}
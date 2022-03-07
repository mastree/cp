#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;

bool cmp(string& a, string& b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<string> v, z;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        if (str == "0") {
            z.emplace_back(str);
        } else {
            v.emplace_back(str);
        }
    }
    if (v.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), greater<string>());
    

    return 0;
}
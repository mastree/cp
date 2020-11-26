#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3;

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    cin.ignore();
    int l = 1, r = N;
    while (l < r){
        int m = (l + r) / 2;
        cout << m << endl;
        string res;
        getline(cin, res);
        if (res == "BENAR") return 0;
        if (res == "LEBIH BESAR"){
            l = m + 1;
        } else{
            r = m - 1;
        }
    }
    cout << l << endl;
    string res;
    getline(cin, res);  

    return 0;
}
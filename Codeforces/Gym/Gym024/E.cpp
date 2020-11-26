#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int M = 10;
const string dcari = "Might Multiplier x";

ll awal;
int n;
vector<ld> mul;

double parse(string& s){
    int len = s.length(), dlen = dcari.length();
    int pos = -1;
    for (int i=0;i + dlen - 1<len;i++){
        for (int j=0;j<dlen;j++){
            if (s[i + j] != dcari[j]) break;
            if (j == dlen - 1) pos = i + j + 1;
        }
        if (pos != -1) break;
    }
    for (int i=pos;i<len;i++){
        s[i - pos] = s[i];
    }
    return stod(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> awal >> n;
    cin.ignore();
    for (int i=1;i<=n;i++){
        string s;
        getline(cin, s);
        mul.pb((ld)parse(s));
    }
    cout << fixed << setprecision(12);
    ld ans = 1;

    for (int i=0;i<(1 << n);i++){
        ld temp = 1;
        for (int j=0;j<n;j++){
            if ((1 << j) & i){
                temp *= mul[j];
            } else{
                temp *= ((ld)1) / mul[j];
            }
        }
        ans *= pow(temp, 1 / (1 << n));
    }
    cout << ans * awal << el;

    return 0;
}
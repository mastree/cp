#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n, k; // 0..n - 1, base

int get10(const vector<int>& vec, const int& base){
    int ret = 0;
    int level = 1;
    int len = vec.size();
    for (int i=0;i<len;i++){
        ret += level * vec[i];
        level *= base;
    }
    return ret;
}
vector<int> add_xor(const vector<int>& a, const vector<int>& b, const int& sign, const int& base){
    int alen = a.size();
    int blen = b.size();
    vector<int> ret(max(alen, blen));
    for (int i=0;i<max(alen, blen);i++){
        if (i < alen) ret[i] += a[i];
        if (i < blen) ret[i] += b[i] * sign;
        ret[i] = (ret[i] % base + base) % base;
    }
    return ret;
}
void increment(vector<int>& a, const int& base){
    if (a.empty()){
        a.pb(1);
        return;
    }
    int len = a.size();
    for (int i=0;i<len;i++){
        a[i] = (a[i] + 1) % base;
        if (a[i] != 0) break;
        if (i == len - 1){
            a.pb(1);
        }
    }
}
int make_query(const vector<int>& a, const int& base){
    int ret;
    cout << get10(a, base) << endl;
    cin >> ret;
    return ret;
}

void solve(){
    int sign = 1;
    vector<int> norming, guess;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        vector<int> temp = add_xor(norming, guess, sign, k);
        int res = make_query(temp, k);
        if (res) break;
        norming = add_xor(temp, norming, -1, k);
        sign = -sign;
        increment(guess, k);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
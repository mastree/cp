#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10, B = 1000;
const ll P = 31;

int n;
string base;

ll shash(string s){
    ll ret = 0, cur = 1;

    int len = s.length();
    for (int i=len - 1;i>=0;i--){
        ret += s[i] * cur;
        cur *= P;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("hash.in", "r", stdin);
    freopen("hash.out", "w", stdout);

    for (int i=1;i<=B;i++){
        base.pb('K');
    }
    cin >> n;
    int cur = 0, i, cur2 = 0; 
    for (i=1;i<=n;i++){
        if (cur >= B) break;
        string temp = base;
        temp[cur] = 'J';
        temp[cur + 1] = 'j';
        cout << temp << el;
        cur += 2;
    }
    if (i > n) return 0;
    base[cur2] = 'J';
    base[cur2 + 1] = 'j';
    cur2 += 2;
    cur = cur2;
    for (;i<=n;i++){
        if (cur >= B) break;
        string temp = base;
        temp[cur] = 'J';
        temp[cur + 1] = 'j';
        cout << temp << el;
        cur += 2;
    }
    if (i > n) return 0;
    base[cur2] = 'J';
    base[cur2 + 1] = 'j';
    cur2 += 2;
    cur = cur2;
    for (;i<=n;i++){
        if (cur >= B) break;
        string temp = base;
        temp[cur] = 'J';
        temp[cur + 1] = 'j';
        cout << temp << el;
        cur += 2;
    }

    return 0;
}
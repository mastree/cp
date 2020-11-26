#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 20;

int n;
string s;
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    if (n <= 2){
        cout << 0 << el;
        return 0;
    }
    int mx = 0;
    for (auto x : s){
        cnt[int(x - '0')]++;
    }
    for (int i=0;i<10;i++){
        mx = max(mx, cnt[i]);
    }
    if (mx > 2){
        cout << n - mx << el;
    } else{
        cout << n - 2 << el;
    }

    return 0;
}
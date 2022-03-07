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
int n;
string s;

bool isvalid(vector<char>& vec){
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (vec[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return 0;
    }
    return cnt == 0;
}

void solve(){
    cin >> n;
    cin >> s;
    s = "*" + s;
    vector<char> a(n + 1), b(n + 1);
    int sisaa = n / 2, sisab = n / 2;
    for (int i=1;i<=n;i++){
        if (s[i] == '0'){
            if (sisaa > sisab){
                a[i] = '(';
                b[i] = ')';
                sisaa--;
            } else{
                b[i] = '(';
                a[i] = ')';
                sisab--;
            }
        }
    }
    if (sisaa < 0 || sisab < 0 || sisaa != sisab){
        cout << "NO" << el;
        return;
    }
    for (int i=1;i<=n;i++){
        if (s[i] == '1'){
            if (sisaa > 0 && sisab > 0){
                a[i] = '(';
                b[i] = '(';
                sisaa--;
                sisab--;
            } else{
                a[i] = ')';
                b[i] = ')';
            }
        }
    }
    if (isvalid(a) && isvalid(b)){
        cout << "YES" << el;
        for (int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << el;
        for (int i=1;i<=n;i++){
            cout << b[i];
        }
        cout << el;
    } else{
        cout << "NO" << el;
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
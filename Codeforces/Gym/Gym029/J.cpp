#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
int n;
int ar[N];
int cnt = 0;

int ask(){
    assert(cnt < n + 500);
    for (int i=1;i<=n;i++){
        cout << ar[i];
    }
    cout << endl;
    int ret;
    cin >> ret;
    cnt++;
    return ret;
}

int res = 0;
void check_dismiss(){
    if (res == n){
        exit(0);
    }
}

void solve(){
    for (int i=1;i<=n;i++){
        ar[i] = (i & 1);
    }
    res = ask();
    check_dismiss();
    if (res != n / 2){
        for (int i=1;i<=n;i++){
            ar[i] = !ar[i];
            if (i % 2 == 0){
                res = ask();
                check_dismiss();
                if (res == n / 2) break;
            }
        }
    }
    assert(res == n / 2);
    vector<int> sama, beda;
    ar[1] = !ar[1];
    for (int i=2;i<n;i++){
        ar[i] = !ar[i];
        res = ask();
        check_dismiss();
        if (res == n / 2){
            beda.pb(i);
        } else{
            sama.pb(i);
        }
        ar[i] = !ar[i];
    }
    if ((int) beda.size() < n / 2){
        beda.pb(n);
    } else{
        sama.pb(n);
    }
    for (auto x : sama){
        ar[x] = !ar[x];
    }
    res = ask();
    check_dismiss();
    for (auto x : sama){
        ar[x] = !ar[x];
    }
    ar[1] = !ar[1];
    for (auto x : beda){
        ar[x] = !ar[x];
    }
    res = ask();
}

int main () {
    cin >> n;
    solve();

    return 0;
}
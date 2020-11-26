#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

void dismiss(int x){
    if (x == 0){
        cout << "TIDAK\n";
    } else{
        cout << "YA\n";
    }
    exit(0);
}

int n, m;
pii ar[N];
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> ar[i].fi >> ar[i].se;
    }    
    int a, b;
    // coba a = ar[i].fi;
    a = ar[1].fi;
    int gada = 0;
    for (int i=1;i<=m;i++){
        if (ar[i].fi == a || ar[i].se == a) continue;
        gada++;
        cnt[ar[i].fi]++;
        cnt[ar[i].se]++;
    }
    for (int i=1;i<N;i++){
        if (gada == cnt[i]){
            dismiss(1);
        }
    }
    fill(cnt, cnt + N, 0);
    a = ar[1].se;
    gada = 0;
    for (int i=1;i<=m;i++){
        if (ar[i].fi == a || ar[i].se == a) continue;
        gada++;
        cnt[ar[i].fi]++;
        cnt[ar[i].se]++;
    }
    for (int i=1;i<N;i++){
        if (gada == cnt[i]){
            dismiss(1);
        }
    }
    dismiss(0);

    return 0;
}
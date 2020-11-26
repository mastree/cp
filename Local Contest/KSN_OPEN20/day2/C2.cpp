#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = (1 << 10) + 10;
const int K = 2;

int n, k;

void solve1(){
    cout << "? 10" << endl;
    int cnt[N];
    memset(cnt, 0, sizeof(cnt));
    int pad = (1 << 9);
    for (int i=1;i<=10;i++){
        bool tan = 1;

        cout << n / 2;
        for (int j=1;j<=n;j++){
            if (tan) cout << ' ' << j;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        cout << endl;
        pad >>= 1;
    }
    pad = (1 << 9);
    for (int i=1;i<=10;i++){
        string res;
        cin >> res;
        
        bool tan = (res == "YA");

        for (int j=1;j<=n;j++){
            if (tan) cnt[j]++;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        pad >>= 1;
    }
    int ans = -1;
    int ada = 0;
    for (int i=1;i<=n;i++){
        if (cnt[i] == 10){
            ans = i;
            ada++;
        }
    }
    assert(ada == 1);
    cout << "! " << ans << endl;
}
int jaw[12][2];

pii cari(int mask){
    int a = -1, b = -1;
    int cnt[N];
    memset(cnt, 0, sizeof(cnt));
    int pad = (1 << 9);
    for (int i=0;i<10;i++){
        bool tan = jaw[i][(mask & (1 << i))];

        for (int j=1;j<=n;j++){
            if (tan) cnt[j]++;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        pad >>= 1;
    }
    for (int i=1;i<=n;i++){
        if (cnt[i] == 10){
            a = i;
        }
    }
    memset(cnt, 0, sizeof(cnt));
    pad = (1 << 9);
    for (int i=0;i<10;i++){
        bool tan = jaw[i][(!(mask & (1 << i)))];

        for (int j=1;j<=n;j++){
            if (tan) cnt[j]++;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        pad >>= 1;
    }
    for (int i=1;i<=n;i++){
        if (cnt[i] == 10){
            b = i;
        }
    }
    if (a == -1 || b == -1) return mp(-1, -1);
    return mp(a, b);
}

bool valid(pii temp){
    int pad = (1 << 9);
    for (int i=0;i<10;i++){
        bool tan = jaw[i][0];

        bool ada = !jaw[i][0];
        for (int j=1;j<=n;j++){
            if (tan && jaw[i][0]){
                if (temp.fi == j || temp.se == j) ada = 1;
            } else if (tan == jaw[i][0]){
                if (temp.fi == j || temp.se == j) return 0;
            }
            if (j % pad == 0){
                tan = !tan;
            }
        }
        if (!ada) return 0;
        pad >>= 1;
    }
    pad = (1 << 9);
    for (int i=0;i<10;i++){
        bool tan = jaw[i][1];

        bool ada = !jaw[i][1];
        for (int j=1;j<=n;j++){
            if (tan && jaw[i][1]){
                if (temp.fi == j || temp.se == j) ada = 1;
            } else if (tan == jaw[i][1]){
                if (temp.fi == j || temp.se == j) return 0;
            }
            if (j % pad == 0){
                tan = !tan;
            }
        }
        if (!ada) return 0;
        pad >>= 1;
    }
    return 1;
}

void solve2(){
    cout << "? 10" << endl;
    int cnt[N];
    memset(cnt, 0, sizeof(cnt));
    int pad = (1 << 9);
    for (int i=1;i<=10;i++){
        bool tan = 1;

        cout << n / 2;
        for (int j=1;j<=n;j++){
            if (tan) cout << ' ' << j;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        cout << endl;
        pad >>= 1;
    }
    pad = (1 << 9);
    for (int i=1;i<=10;i++){
        string res;
        cin >> res;
        jaw[i - 1][0] = (res == "YA");
        // if (res == "TIDAK") continue;
        // bool tan = 1;

        // for (int j=1;j<=n;j++){
        //     if (tan) cnt[j]++;
        //     if (j % pad == 0){
        //         tan = !tan;
        //     }
        // }
        // pad >>= 1;
    }
    cout << "? 10" << endl;
    pad = (1 << 9);
    for (int i=1;i<=10;i++){
        bool tan = 0;

        cout << n / 2;
        for (int j=1;j<=n;j++){
            if (tan) cout << ' ' << j;
            if (j % pad == 0){
                tan = !tan;
            }
        }
        cout << endl;
        pad >>= 1;
    }
    pad = (1 << 9);
    for (int i=1;i<=10;i++){
        string res;
        cin >> res;
        jaw[i - 1][1] = (res == "YA");
        // if (res == "TIDAK") continue;
        // bool tan = 0;

        // for (int j=1;j<=n;j++){
        //     if (tan) cnt[j]++;
        //     if (j % pad == 0){
        //         tan = !tan;
        //     }
        // }
        // pad >>= 1;
    }
    pii ans = mp(-1, -1);
    for (int i=0;i<(1 << 10);i++){
        pii temp = cari(i);
        if (temp.fi != temp.se && valid(temp)){
            ans = temp;
            break;
        }
    }
    cout << "! " << ans.fi << " " << ans.se << endl;
}

int main () {
    cin >> n >> k;
    if (n == k){
        if (n == 1) cout << "! 1" << endl;
        if (n == 2) cout << "! 1 2" << endl;
        return 0;
    }
    if (k == 1){
        solve1();
    } else {
        solve2();
    }

    return 0;
}
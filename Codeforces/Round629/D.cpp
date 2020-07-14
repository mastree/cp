#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;

int q;
int n;
int ar[N];

int col[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }

        fill(col, col + n + 2, 0);
        int awal = 1;
        for (int i=2;i<=n;i++){
            if (ar[i] == ar[1]) awal++;
            else break;
        }
        if (awal == n) awal = 1;
        else{
            awal++;
        }
        // cout << awal << el;

        int geser = 1 - awal;
        int temp[n + 2];
        for (int i=1;i<=n;i++){
            int id = i - geser;
            if (id > n) id -= n;
            temp[i] = ar[id];
        }

        vector <int> v;
        int bef = 0, cnt = 0;
        for (int i=1;i<=n;i++){
            if (bef == temp[i]){
                cnt++;
            } else{
                if (bef == 0){
                    bef = temp[i];
                    cnt = 1;
                } else{
                    v.pb(cnt);
                    bef = temp[i];
                    cnt = 1;
                }
            }
        }
        v.pb(cnt);
        // for (auto x : v){
        //     cout << x << " ";
        // }
        // cout << el;

        if (v.size() == 1){
            cout << 1 << el;
            for (int i=1;i<=n;i++){
                cout << 1 << " ";
            }
            cout << el;
            continue;
        }

        int ans[n + 2];
        cnt = 2;
        if (v.size() % 2 == 0){
            int id = 1;
            int isi = 1;
            for (auto x : v){
                while (x--){
                    ans[id] = isi;
                    id++;
                }
                isi = isi % 2 + 1;
            }
        } else{
            cnt = 3;
            int id = 1;
            int isi = 1;
            int i;
            for (i=0;i<v.size();i++){
                if (v[i] > 1){
                    cnt = 2;
                    break;
                }
            }

            if (cnt == 2){
                for (int j=0;j<v.size();j++){
                    if (j == i){
                        ans[id] = isi;
                        v[i]--;
                        isi = isi % cnt + 1;
                        id++;
                    }

                    while (v[j]--){
                        ans[id] = isi;
                        id++;
                    }
                    isi = isi % cnt + 1;

                }
            } else{
                ans[1] = 1;
                for (int i=1;i<=n;i++){
                    int le = i - 1;
                    int ri = i + 1;

                    if (ri == n + 1) ri = 1;

                    int c = 1;
                    if (c == ans[le] || c == ans[ri]) c++;
                    if (c == ans[le] || c == ans[ri]) c++;
                    ans[i] = c;
                }
            }

        }

        cout << cnt << el;
        for (int i=1;i<=n;i++){
            int id = i + geser;
            if (id <= 0) id += n;
            cout << ans[id] << " ";
        }
        cout << el;
    }

    return 0;
}
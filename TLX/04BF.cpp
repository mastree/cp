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

const int N = 10;

int n, q;
int ar[N];
int stat[N * 2];
vector <pii> tanding;
int len;

bool cek(int last){
    if (last == len){
        int skor[n + 1];
        fill(skor, skor + n + 1, 0);
        for (int i=0;i<len;i++){
            pii temp = tanding[i];
            if (stat[i] == 0){
                skor[temp.fi] += 3;
            } else if (stat[i] == 1){
                skor[temp.fi] += 1;
                skor[temp.se] += 1;
            } else{
                skor[temp.se] += 3;
            }
        }
        bool ret = 1;
        for (int i=1;i<=n;i++){
            if (skor[i] != ar[i]){
                ret = 0;
                break;
            }
        }
        return ret;
    }
    bool ret = 0;
    stat[last] = 0;
    ret |= cek(last + 1);
    stat[last]++;
    ret |= cek(last + 1);
    stat[last]++;
    ret |= cek(last + 1);
    return ret;
}

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
        tanding.clear();
        for (int i=1;i<=n;i++){
            for (int j=i + 1;j<=n;j++){
                tanding.pb(mp(i, j));
            }
        }
        len = tanding.size();

        fill(stat, stat + len + 1, 0);
        if (cek(0)){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}
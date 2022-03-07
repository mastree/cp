#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 550;
const int VAL = 100;

const string color = "WBR";

int getval(char c){
    for (int i=0;i<3;i++){
        if (c == color[i]) return i;
    }
    return 4;
}

int getid(const vector<int>& vec){
    int ret = 0;
    for (auto& x : vec){
        ret = ret * 3 + x;
    }
    return ret;
}

vector<int> rotate(const vector<int>& vec){
    vector<int> ret = {vec[2], vec[0], vec[3], vec[1]};
    return ret;
}

int k;
int cnt[VAL];
int n, m;
int ar[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i=1;i<=k;i++){
        vector<int> vec;
        for (int j=0;j<4;j++){
            char c;
            cin >> c;
            vec.pb(getval(c));
        }
        cnt[getid(vec)]++;
    }
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            ar[i][j] = getval(c);
        }
    }
    bool ok = 1;
    for (int i=1;i<=n;i+=2){
        for (int j=1;j<=m;j+=2){
            vector<int> vec;
            for (int ii=0;ii<2;ii++){
                for (int jj=0;jj<2;jj++){
                    vec.pb(ar[i + ii][j + jj]);
                }
            }
            int lup = 0;
            while (cnt[getid(vec)] <= 0 && lup < 3){
                lup++;
                vec = rotate(vec);
            }
            if (cnt[getid(vec)]){
                cnt[getid(vec)]--;
            } else{
                ok = 0;
                break;
            }
        }
        if (!ok) break;
    }
    if (ok) cout << "Yes" << el;
    else cout << "No" << el;

    return 0;
}
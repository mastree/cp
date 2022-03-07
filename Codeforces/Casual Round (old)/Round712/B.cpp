#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int n;
int mat[N][N];
vector<pii> veca, vecb;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if ((i + j) & 1){
                vecb.pb(mp(i, j));
            } else{
                veca.pb(mp(i, j));
            }
        }
    }
    for (int i=1;i<=n * n;i++){
        int nope;
        cin >> nope;

        if (nope == 1){
            if (!vecb.empty()){
                auto temp = vecb.back();
                vecb.pop_back();
                cout << 2 << " " << temp.fi << " " << temp.se << endl;
            } else{
                auto temp = veca.back();
                veca.pop_back();
                cout << 3 << " " << temp.fi << " " << temp.se << endl;
            }
        } else if (nope == 2){
            if (!veca.empty()){
                auto temp = veca.back();
                veca.pop_back();
                cout << 1 << " " << temp.fi << " " << temp.se << endl;
            } else{
                auto temp = vecb.back();
                vecb.pop_back();
                cout << 3 << " " << temp.fi << " " << temp.se << endl;
            }
        } else{
            if (!veca.empty()){
                auto temp = veca.back();
                veca.pop_back();
                cout << 1 << " " << temp.fi << " " << temp.se << endl;
            } else if (!vecb.empty()){
                auto temp = vecb.back();
                vecb.pop_back();
                cout << 2 << " " << temp.fi << " " << temp.se << endl;
            }
        }
    }

    return 0;
}
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

int n, q;
int ar[2][N];
int stat[2][N];
set <int> block;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (q--){
        int r, c;
        cin >> r >> c;
        r--;
        if (!stat[r][c]){
            stat[r][c] = 1;
            ar[r][c]++;
            ar[r][c+1]++;
        } else{
            stat[r][c] = 0;
            ar[r][c]--;
            ar[r][c+1]--;
        }
        // for (int i=0;i<2;i++){
        //     for (int j=1;j<=n;j++){
        //         cout << ar[i][j] << " ";
        //     }
        //     cout << el;
        // }
        // cout << r << " " << !r << " => " << ar[r][c] + ar[!r][c] << el;
        if (ar[r][c] && ar[!r][c]){
            // cout << "tes" << el;
            block.insert(c);
            // cout << block.empty() << el;
        } else{
            auto it = block.find(c);
            if (it != block.end()){
                block.erase(it);
            }
        }
        if (c+1 <= n){
            if (ar[r][c+1] && ar[!r][c+1]){
                block.insert(c + 1);
            } else{
                auto it = block.find(c + 1);
                if (it != block.end()){
                    block.erase(it);
                }
            }
        }

        if (block.empty()){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}
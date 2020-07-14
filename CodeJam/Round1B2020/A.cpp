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

const int N = 31;

int q;
ll realx, realy;
ll x, y;

string movement = "*NSEW";

string sol(){
    cin >> realx >> realy;
    x = abs(realx);
    y = abs(realy);

    int bitx[N + 2], bity[N + 2];
    for (int i=0;i<N;i++){
        int temp = (1 << i);
        if (temp & x){
            bitx[i] = 1;
        } else{
            bitx[i] = 0;
        }
        if (temp & y){
            bity[i] = 1;
        } else{
            bity[i] = 0;
        }
    }

    int hasil[N];
    fill(hasil, hasil + N, 0);

    int lazyx = 0, lazyy = 0;
    for (int i=0;i<N;i++){
        // cout << lazyy << el;
        if (lazyx == 1){
            if (bitx[i]){
                bitx[i] = 0;
            } else{
                lazyx = 0;
                bitx[i] = 1;
            }
        } else if (lazyx == 2){
            lazyx = 1;
        }
        if (lazyy == 1){
            if (bity[i]){
                bity[i] = 0;
            } else{
                lazyy = 0;
                bity[i] = 1;
            }
        } else if (lazyy == 2){
            lazyy = 1;
        }
        if (bitx[i] && bity[i]){
            if (i == 0 || hasil[i - 1] == 0){
                return "IMPOSSIBLE";
            }
            if (hasil[i - 1] == 1){
                hasil[i - 1] = -1;
                hasil[i] = 2;
                lazyx++;
            } else{
                hasil[i - 1] = -2;
                hasil[i] = 1;
                lazyy++;
            }
        } else if (bitx[i]){
            hasil[i] = 1;
        } else if (bity[i]){
            hasil[i] = 2;
        }
        // cout << hasil[i] << el;
    }
    bool nemu = 0;
    for (int i=30;i>=0;i--){
        if (hasil[i] != 0) nemu = 1;
        if (hasil[i] == 0 && nemu){
            int j = i;
            for (j;j>0;j--){
                if (hasil[j]) break;
            }
            hasil[i] = hasil[j];
            for (int k=i-1;k>=j;k--){
                hasil[k] = -hasil[j];
            }
        }
    }
    // cout << el;

    string res;
    if (realx != x){
        for (int i=0;i<N;i++){
            if (abs(hasil[i]) == 1){
                hasil[i] *= -1;
            } 
        }
    }
    if (realy != y){
        for (int i=0;i<N;i++){
            if (abs(hasil[i]) == 2){
                hasil[i] *= -1;
            } 
        }
    }
    for (int i=0;i<N;i++){
        if (hasil[i] == 1){
            res.pb('E');
        } 
        if (hasil[i] == -1){
            res.pb('W');
        } 
        if (hasil[i] == 2){
            res.pb('N');
        } 
        if (hasil[i] == -2){
            res.pb('S');
        } 
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Case #" << cas << ": ";
        cout << sol() << el;
    }

    return 0;
}
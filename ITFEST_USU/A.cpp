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

const int N = 5e4 + 10;

int q;
int n;
int ar[N];

void rot(int i){
    vector <int> v;
    v.pb(ar[i + 1]);
    v.pb(ar[i + 2]);
    v.pb(ar[i]);
    for (int id=i;id<i+3;id++){
        ar[id] = v[id - i];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cin >> q;
    // while (q--){
    //     cin >> n;
    //     for (int i=1;i<=n;i++){
    //         cin >> ar[i];
    //     }
    //     if (n > 3){
    //         cout << "YES" << el;
    //         continue;
    //     }
    //     bool yes = 0;
    //     int temp[3] = {ar[1], ar[2], ar[3]};
    //     if (temp[0] < temp[1] && temp[1] < temp[2]){
    //         yes = 1;
    //     }
    //     if (temp[1] < temp[2] && temp[2] < temp[0]){
    //         yes = 1;
    //     }
    //     if (temp[2] < temp[0] && temp[0] < temp[1]){
    //         yes = 1;
    //     }

    //     if (yes) {
    //         cout << "YES" << el;
    //     } else{
    //         cout << "NO" << el;
    //     }
    // }

    for (int i=1;i<=5;i++){
        ar[i] = i;
    }
    for (int id=0;id<5;id++){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                int cek = 0;
                for (int k=1;k<=5;k++){
                    cout << ar[k] << " ";
                    for (int l=1;l<k;l++){
                        if (ar[l] > ar[k]) cek++;
                    }
                }
                cout << cek << el;
                rot(3);
            }
            rot(2);
        }
        rot(1);
    }

    return 0;
}
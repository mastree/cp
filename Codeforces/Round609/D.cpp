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

const int N = 3e5 + 11;

int n;
ll ar[N], isi[N], tot=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ar[0]=-1;

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        isi[i] = ar[i];
    }

    bool sisa = 0, kbwh = 1, h;
    for (int i=1;i<=n;i++){
        // if (ar[i]&1){
        //     tot+=ar[i]/2;
        //     ar[i]=1;
        // } else{
        //     if (ar[i]){
        //         if (ar[i+1]%2==0){
        //             tot+=(ar[i]-ar[i+1])/2;
        //             tot+=ar[i+1]-1;
        //             ar[i]=1;
        //             ar[i+1]=1;
        //             i++;
        //         }
        //     } else{
        //         tot+=ar[i]/2;
        //         ar[i]=0;
        //     }
        // }
        if (kbwh){
            if (sisa){
                if (ar[i]>=h && ar[i]){
                    tot++;
                    isi[i]--;
                }
            } 
            tot+=isi[i]/2;
            sisa = (isi[i]%2);

            // sisa = (isi[i]);
            //kbwh = (!sisa);
        } //else{
        //     if (sisa){
        //         if (ar[i]) {
        //             tot++;
        //             isi[i]--;
        //         }
        //     }
        //     tot+=isi[i]/2;
        //     // isi[i]
        //     sisa = (isi[i]%2);

        //     kbwh=1;
        // }
        // cout << tot << " => " << kbwh << " " << sisa << " sisa: " << isi[i] << el;
    }

    // if (ar[n]>1){
    //     tot+=ar[n]/2;
    //     ar[n]%=2;
    // }

    // cout << tot << el;
    // for (int i=1;i<=n;i++){
    //     cout << ar[i] << " ";
    // }
    // cout << el;

    // for (int i=1;i<=n-1;i++){
    //     if (ar[i] && ar[i+1]){
    //         tot++;
    //         i++;
    //     }
    // }
    cout << tot << el;

    return 0;
}
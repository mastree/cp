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

int n;
int ar[20008];
int od;
bool cek[20008];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
        if (ar[i]&1){
            od++;
            cek[i]=1;
        }
    }

    int tot=0;
    for (int i=0;i<n;i++){
        if (ar[i]&1){
            if (ar[i]>0){
                ar[i]/=2;
            } else{
                ar[i]/=2;
                ar[i]-=1;
            }
        } else{
            ar[i]/=2;
        }

        tot+=ar[i];
    }

    for (int i=0;i<n;i++){
        if (tot<0){
            if (cek[i]){
                ar[i]++;
                tot++;
            }
        }
    }

    for (int i=0;i<n;i++){
        cout << ar[i] << el;
    }

    return 0;
}
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

const int N = 100007;

int n;
int in[N], out[N], pos[N];
int bit[N];

void upd(int id, int val){
    while (id<=n){
        bit[id]+=val;
        id=id+(id&(-id));
    }
}
 
int ask(int a, int b){
    int resa=0,resb=0;
 
    a--;
    while (a>0){
        resa+=bit[a];
        a=a-(a&(-a));
    }
 
    while (b>0){
        resb+=bit[b];
        b=b-(b&(-b));
    }
 
    return resb-resa;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> in[i];
        pos[in[i]]=i;
        upd(i,1);
    }

    for (int i=1;i<=n;i++){
        cin >> out[i];
    }

    int ans=0;
    for (int i=1;i<=n;i++){
        upd(pos[out[i]],-1);
        int cek=ask(1,pos[out[i]]-1);
    //    cout << cek << el;
        if (cek){
            ans++;
        }
    }

    cout << ans << el;

    return 0;
}
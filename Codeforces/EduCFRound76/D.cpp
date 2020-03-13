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

const int N = 200010;

int q;
int stree_pow[N*4]; // hero's power
int stree_cek[N*4]; // monster max power
int mon[N];
int hero[N];
int n, m, sisa;

void constree_cek(int low, int high, int pos){
    if (low==high){
        stree_cek[pos]=mon[low];
        return;
    }
 
    int left=pos*2+1, mid=(low+high)/2;
    constree_cek(low,mid,left);
    constree_cek(mid+1,high,left+1);
 
    stree_cek[pos]=max(stree_cek[left],stree_cek[left+1]);
}
 
int ask_cek(int qlow, int qhigh, int low, int high, int pos){
    if (qlow>high || qhigh<low){
        return -1;
    }
 
    if (qlow<=low && qhigh>=high){
        return stree_cek[pos];
    }
 
    int left=pos*2+1, mid=(low+high)/2;
    int res1=ask_cek(qlow,qhigh,low,mid,left);
    int res2=ask_cek(qlow,qhigh,mid+1,high,left+1);
 
    return max(res1,res2);
}

void constree_pow(int low, int high, int pos){
    if (low==high){
        stree_pow[pos]=hero[low];
        return;
    }
 
    int left=pos*2+1, mid=(low+high)/2;
    constree_pow(low,mid,left);
    constree_pow(mid+1,high,left+1);
 
    stree_pow[pos]=max(stree_pow[left],stree_pow[left+1]);
}
 
int ask_pow(int qlow, int qhigh, int low, int high, int pos){
    if (qlow>high || qhigh<low){
        return -1;
    }
 
    if (qlow<=low && qhigh>=high){
        return stree_pow[pos];
    }
 
    int left=pos*2+1, mid=(low+high)/2;
    int res1=ask_pow(qlow,qhigh,low,mid,left);
    int res2=ask_pow(qlow,qhigh,mid+1,high,left+1);
 
    return max(res1,res2);
}

bool play(int a){
    int mona=n-sisa+1, monb=mona+a-1;
    int monmax = ask_cek(mona, monb, 1, n, 0);

    int hermax = ask_pow(a, n, 1, n, 0);

    return hermax>=monmax;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> n;
        sisa = n;

        int maxmon=-1, maxhero=-1;
        for (int i=1;i<=n;i++){
            cin >> mon[i];
            maxmon = max(maxmon,mon[i]);

            hero[i]=0; // power initialize
        }

        cin >> m;
        for (int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            maxhero = max(maxhero, a);
            hero[b] = max(hero[b], a);
        }

        if (maxhero<maxmon){
            cout << -1 << el;
            continue;
        }

        constree_cek(1,n,0);
        constree_pow(1,n,0);

        int ans=0;
        while (sisa){
            int low = 1, high = sisa;

            while (low<high){
                int mid = (low+high+1)/2;

                if (play(mid)){
                    low = mid;
                } else{
                    high = mid-1;
                }
            }

            sisa-=low;
            ans++;
        }

        cout << ans << el;
    }

    return 0;
}
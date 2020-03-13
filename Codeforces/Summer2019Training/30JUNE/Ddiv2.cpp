#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 300010;

stack <int> st[N];
int segtree[N*4];
int ar1[N],ar2[N];
int n;

int gettop(int id){
    if (!st[id].empty()){
        return st[id].top();
    }
    return -1;
}

void constree(int low,int high,int pos){
    if (low==high){
        segtree[pos]=gettop(low);
        return;
    }
    
    int left=pos+pos+1,mid=(low+high)/2;

    constree(low,mid,left);
    constree(mid+1,high,left+1);

    segtree[pos]=max(segtree[left],segtree[left+1]);
}

void upd(int low,int high,int id,int pos){
    if (high<id) return;
    if (low>id) return;
    
    if (low==high){
        segtree[pos]=gettop(id);return;
    }
    
    int mid=(low+high)/2,left=pos+pos+1;
    upd(low,mid,id,left);
    upd(mid+1,high,id,left+1);
    
    segtree[pos]=max(segtree[left],segtree[left+1]);
}

int getmax(int low,int high,int qlow,int qhigh,int pos){
    if (low>qhigh) return -1;
    if (high<qlow) return -1;

    if (qlow<=low && qhigh>=high) return segtree[pos];
    int mid=(low+high)/2,left=pos+pos+1;

    return max(getmax(low,mid,qlow,qhigh,left),getmax(mid+1,high,qlow,qhigh,left+1));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    
    while (q--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> ar1[i];
        for (int i=0;i<n;i++) cin >> ar2[i];
        for (int i=1;i<=n;i++){
            while (!st[i].empty()) st[i].pop();
        }

        for (int i=0;i<n;i++){
            st[ar1[i]].push(i);
        }

        constree(1,n,0);

        bool bisa=1;
        for (int i=n-1;i>=0;i--){
            int mk=getmax(1,n,ar2[i],n,0);
            if (mk==-1){
                bisa=0;
                break;
            }
            if (mk==gettop(ar2[i])){
                st[ar2[i]].pop();
                upd(1,n,ar2[i],0);
                continue;
            }

            bisa=0;
            break;
        }

        if (bisa) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}
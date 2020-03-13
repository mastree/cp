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

double ar[5];
double tot;
double tar;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<4;i++){
        cin >> ar[i];
        // tot += ar[i];
        ar[i] *= 100;
    }
    sort(ar, ar + 4);
    tot = ar[1] + ar[2] + ar[3];
    cin >> tar;
    tar *= 100;
    double avg = tot/3;
    if (avg <= tar){
        cout << "infinite" << el;
        return 0;
    }
    tot = ar[0] + ar[1] + ar[2];
    avg = tot/3;
    if (avg > tar){
        cout << "impossible" << el;
        return 0;
    }
    tot = ar[1] + ar[2];
    cout << fixed << setprecision(2) << (tar*3.0 - tot)/100.0 << el;

    return 0;
}
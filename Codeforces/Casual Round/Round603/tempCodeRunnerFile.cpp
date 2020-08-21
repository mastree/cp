or (int i=0;i<n;i++){
    //     int baru = s[i];
    //     if (baru == 'R'){
    //         ed++;
    //         if (tot==0){
    //             if (query(1, st, ed, st, ed) >= 0){
    //                 cout << 1 << " ";
    //             } else{
    //                 cout << -1 << " ";
    //             }
    //         }
    //         continue;
    //     } else if (baru == 'L') {
    //         cur = max(0, cur-1);
    //         if (tot==0){
    //             if (query(1, st, ed, st, ed) >= 0){
    //                 cout << 1 << " ";
    //             } else{
    //                 cout << -1 << " ";
    //             }
    //         }
    //         continue;
    //     }

    //     int tm;
    //     if (baru == '('){
    //         tm=1;
    //     } else if (baru == ')'){
    //         tm=-1;
    //     } else{
    //         tm=0;
    //     }
    //     int sel = tm-ar[cur];
    //     ar[cur] = tm;
    //     tot+=sel;

    //     update(1, st, ed, cur, ed, sel);

    //     if (tot==0){
    //         if (query(1, st, ed, st, ed) >= 0){
    //             cout << 1 << " ";
    //         } else{
    //             cout << -1 << " ";
    //         }
    //     }
    // }
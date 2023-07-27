int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int plats = 1, ans = 1;
    int i = 1, j = 0;
    while(i<n && j<n) {
        if(at[i] <= dt[j]) {
            plats++;
            i++;
        } else {
            plats--;
            j++;
        }
        ans = max(ans, plats);
    }
    return ans;
}
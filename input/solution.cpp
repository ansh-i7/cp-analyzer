
/* {
    for(int i=0;i<n;i++)
}

 for(int i=0;i<n;i++) {
    // inner loop starts below
    for(int j=0;j<n;j++) {
        cout << i << j;
    }
} */

int solve(int n) {
    if (n == 0) return 0;
    return solve(n - 1);
}

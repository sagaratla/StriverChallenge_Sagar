vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xr = 0;
    // xr has XOR of all numbers
    for(int i=0;i<n;i++) {
        xr = xr ^ (i+1);
        xr = xr ^ A[i];
    }
    
    // find the set bit from right
    int bitPos = 0;
    while(true) {
        if(1 & (xr>>bitPos) == 1) {
            break;
        }
        bitPos++;
    }
    
    // initialize with 0 since ((number XOR 0) = number)
    int zeroClub = 0, oneClub = 0;
    for(int i=0;i<n;i++) {
        // belongs to one oneClub
        if(((A[i]>>bitPos) & 1) == 1) {
            oneClub = oneClub ^ A[i]; 
        } else { // belongs to zeroClub
            zeroClub = zeroClub ^ A[i]; 
        }
    }
    
    for(int i=1;i<=n;i++) {
        // belongs to one oneClub
        if(((i>>bitPos) & 1) == 1) {
            oneClub = oneClub ^ i; 
        } else { // belongs to zeroClub
            zeroClub = zeroClub ^ i; 
        }
    }
    
    for(int i=0;i<n;i++) {
        if(A[i] == zeroClub) {
            return {zeroClub, oneClub};
        }
    }
    return {oneClub, zeroClub};
}

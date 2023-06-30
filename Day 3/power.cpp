class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long n_mod = n;
        
        if(n_mod < 0) {
            n_mod = (-1 * n_mod);
        }
        
        while(n_mod != 0) {
            // even
            if(n_mod % 2 == 0) {
                x = x*x;
                n_mod /= 2;
            } else {
                // odd
                ans = ans * x;
                n_mod--;
            }
        }
        
        if(n < 0) {
            return 1.0 / ans;
        }
        return ans;
    }
};
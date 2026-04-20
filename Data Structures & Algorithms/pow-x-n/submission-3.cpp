class Solution {
public:

    double binpow(double a, long long b) {
        double res = 1;
        bool neg = false;
        if(b<0){b=abs(b); neg =true;}
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        if(neg)return 1/res; 
        return res;
    }
    double myPow(double x, int n) {
        return binpow(x,n);
    }
};

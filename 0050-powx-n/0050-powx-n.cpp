class Solution {
public:
    double myPow(double x, int n) {
        long long ans=1;
        if(n==0)
        return 1;
        if(n<0){
            if (n == INT_MIN) {
                return 1 / (myPow(x, INT_MAX) * x);
            }
            long long N=n;
            return 1/myPow(x,-N);
        }
        if(n%2==0){
            return res(x,n/2);
        }
        else{
            return x*res(x,(n-1)/2);
        }
    }
    double res(double x ,int n){
        double ans=myPow(x,n);
        return ans*ans;
    }
};
class Solution {
public:
    int findIntegers(int n) {
        int fib[32];
        fib[0] = 1;
        fib[1] = 2;
        for(int i=2;i<32;++i){
            fib[i] = fib[i-1]+fib[i-2];
        }
        int msb = 31,ans = 0;
        bool prevBitOne = false;
        while(msb>=0){
            if(n&(1<<msb)){
                ans+=fib[msb];
                if(prevBitOne){
                    return ans;
                }
                prevBitOne = true;
            }else{
                prevBitOne = false;
            }
            msb--;
        }
        return ans+1;
    }
};
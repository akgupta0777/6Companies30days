class Solution {
public:
    long getCount(long n,long first,long second){
        long steps=0;
        while(first<=n){
            steps += min(n+1,second)-first;
            first*=10;
            second*=10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int result=1;
        k-=1;
        while(k>0){
            long count = getCount(n,result,result+1);
            if(count<=k){
                result+=1;
                k-=count;
            }else{
                result*=10;
                k--;
            }
        }
        return result;
    }
};
class Solution {
public:
    int magicalString(int n) {
        if(n<=3) return 1;
        int arr[n+1];
        arr[0]=1,arr[1]=arr[2]=2;
        int head=2,tail=3,num=1;
        int result=1;
        while(tail<n){
            for(int i=0;i<arr[head];++i){
                if(tail<n && num==1) result++;
                arr[tail++]=num;
            }
            num^=3;
            head++;
        }
        return result;
    }
};
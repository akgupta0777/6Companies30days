class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int maxCount=0,maxCode=0;
        unordered_map<int,int> count;
        int pos = 0,n = barcodes.size();
        bool reachedOdd = false;
        for(int code : barcodes){
            maxCount = max(maxCount,++count[code]);
            maxCode = count[code]==maxCount ? code : maxCode;
        }
        for(int i=0;i<=10000;++i){
            int val = i==0 ? maxCode : i;
            while(count[val]-- > 0){
                barcodes[pos] = val;
                if(pos+2<n){
                    pos+=2;
                }else{
                    if(reachedOdd) break;
                    pos = 1;
                    reachedOdd = true;
                }
                // pos = pos+2 < n ? pos+2 : 1;
            }
        }
        return barcodes;
    }
};
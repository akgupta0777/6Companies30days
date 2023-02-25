//Effiecient Solution
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        int maxScore = k-1+maxPts;
        if(k==0 || n >= maxScore) return 1.0;
        vector<double> probability(n+1,0.0);
        probability[0] = 1.0;
        double probabilitySum = 1.0;
        double result=0;
        for(int i=1;i<=n;++i){
            probability[i]=(probabilitySum/(double)maxPts);
            if(i<k) probabilitySum+=probability[i];
            else{
                result+=probability[i];
            }
            if(i-maxPts>=0){
                probabilitySum-=probability[i-maxPts];
            }
        }
        return result;
    }
};
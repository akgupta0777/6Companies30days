class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        for(int x : left){
            lastMoment = max(lastMoment,x);
        }
        for(int x : right){
            lastMoment = max(lastMoment,n-x);
        }
        return lastMoment;
    }
};
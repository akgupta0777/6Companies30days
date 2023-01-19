/*
Explanation:
Approach is backtracking we are going on each of the section and exploring available options either we win
or loose if we win we get the score of the section and then backtrack to explore other options and finally
maximizing the score.
*/

class Solution {
public:
    int maxScore = 0;
    vector<int> bobArrows;
    void getMaxScore(int section,int score,int numArrows,vector<int>& aliceArrows,vector<int>& bobArrows,vector<int>& result){
        if(section<0 || numArrows<=0){
            if(score>maxScore){
                bobArrows=result;
                maxScore = score;
                if(numArrows>0){
                    bobArrows[0]+=numArrows;
                }
            }
            return ;
        }
        int requiredArrows = aliceArrows[section]+1;
        if(numArrows>=requiredArrows){
            int prevArrows = result[section];
            result[section]+=requiredArrows;
            getMaxScore(section-1,score+section,numArrows-requiredArrows,aliceArrows,bobArrows,result);
            result[section] = prevArrows;
        }
        getMaxScore(section-1,score,numArrows,aliceArrows,bobArrows,result);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        bobArrows.resize(12,0);
        vector<int> result(12,0);
        getMaxScore(11,0,numArrows,aliceArrows,bobArrows,result);
        return bobArrows;
    }
};
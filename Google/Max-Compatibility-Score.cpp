class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> indices;
        for(int i=0;i<students.size();++i){
            indices.push_back(i);
        }
            int maxScore = 0;
        do{
            int score = 0;
            for(int i=0;i<students.size();++i){
                for(int j=0;j<students[0].size();++j){
                    score += (students[indices[i]][j] == mentors[i][j]);
                }
            }
            maxScore = max(maxScore,score);
        }while(next_permutation(indices.begin(),indices.end()));
        return maxScore;
    }

};
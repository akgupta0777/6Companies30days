/*
Explanation:
Intuition
As learnt in school if some set of points have a common slope then they are on the same line. The only 
condition is one point should be common which originates that line which have the same slope.

Approach
Here we used brute force way of solving the problem since the constraints are low.
We basically tried every set of points and use a map to store how many points have same slope.
Finally we calculate maximum points having same slope and updated the result accordingly.

Calculating slope for points (x1,y1) and (x2,y2)
Slope = (y2-y1)/(x2-x1)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        int result=0;
        unordered_map<double,int> slopes;
        double slope = 0;
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                slope = ((double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]));
                cout<<slope<<"\n";
                if((points[j][0]-points[i][0])==0){
                    slope=DBL_MAX;
                }
                slopes[slope]++;
            }
            for(auto [slope,cnt]:slopes){
                result = max(result,cnt+1);
            }
            slopes.clear();
        }
        return result;
    }
};
/*
Explanation:
BruteForce approach we applied here with a hashmap as constraints are low.
What we did is we store number of points which has same distance in a hashmap and then count pairs from it
with the formula (count*(count-1))
*/


class Solution {
public:
    long long getDistance(vector<int>& p1,vector<int>& p2){
        long long distance=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        return distance;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<long long,long long> distMap;
        int n=points.size();
        int boomerangs=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue;
                distMap[getDistance(points[i],points[j])]++;
            }
            for(auto [dist,count]:distMap){
                if(count>=2){
                    boomerangs+=count*(count-1);
                }
            }
            distMap.clear();
        }
        return boomerangs;
    }
};
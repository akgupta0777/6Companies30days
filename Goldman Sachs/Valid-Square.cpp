/*
Explanation:
For a valid square check distance from each point. We should only find 2 distances one for sides and one
for diagonals. If distance is 0 it means a point is repeated so we need to return false. 
Return true if there are only 2 points.
*/

class Solution {
public:
    long getDistance(vector<int>& p1,vector<int>& p2){
        long distance = ((p1[0]-p2[0])*(p1[0]-p2[0])) + ((p1[1]-p2[1])*(p1[1]-p2[1]));
        return distance;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long> distances = {getDistance(p1,p2),getDistance(p1,p3),getDistance(p1,p4),getDistance(p2,p3),getDistance(p2,p4),getDistance(p3,p4)};
        return !distances.count(0) && distances.size()==2;
    }
};
/*
Explanation:
Two points to observe:
1) Sum of all the small rectangles area should be equal to large rectangle area.
2) A rectangular cover should only have 4 corner points.

Approach:
We are maintaining 4 variables maxX,minX,maxY,minY to maintain minimum X,Y and maximum X,Y points of the
bigger rectangle that will be the final cover.
We will use a set to store these co-ordinates and whenever we found a co-ordinate that is already in set
it simply means that the rectangle is touching another rectangle.
Finally check the sum of area to be equal to larger rectangle.

Algorithm:
Run a loop through all the rectangles to process them.
Maximise and minimize the larger rectangle co-ordinates accordingly.
Add the sum of all rectangle area.
Add or remove corners from the set accordingly.
Lastly check the conditions if corners of bigger rectangle is present or not. If not return false.
Finally check area of smaller rectangels equal to larger rectangle and return the result.
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size()==1) return true;
        set<pair<int,int>> corners;
        int x1,x2,y1,y2;
        long long area=0;
        int maxX=INT_MIN,minX=INT_MAX,maxY=INT_MIN,minY=INT_MAX;
        for(vector<int> rectangle : rectangles){
            x1=rectangle[0];
            y1=rectangle[1];
            x2=rectangle[2];
            y2=rectangle[3];
            maxX=max(maxX,x2);
            maxY=max(maxY,y2);
            minX=min(minX,x1);
            minY=min(minY,y1);
            area+=(x2-x1)*(y2-y1);
            pair<int,int> corner1={x1,y1};
            pair<int,int> corner2={x2,y2};
            pair<int,int> corner3={x1,y2};
            pair<int,int> corner4={x2,y1};
            
            if(corners.count(corner1)){
                corners.erase(corner1);
            }else{
                corners.insert(corner1);
            }

            if(corners.count(corner2)){
                corners.erase(corner2);
            }else{
                corners.insert(corner2);
            }

            if(corners.count(corner3)){
                corners.erase(corner3);
            }else{
                corners.insert(corner3);
            }

            if(corners.count(corner4)){
                corners.erase(corner4);
            }else{
                corners.insert(corner4);
            } 
        }
        if(corners.size()!=4 || !corners.count({minX,minY}) || !corners.count({minX,maxY}) || !corners.count({maxX,minY}) || !corners.count({maxX,maxY})){
            return false;
        }
        
        return area == (maxX-minX)*(maxY-minY);
    }
};
/*
Explanation:
We traverse all the 8 possible moves and get the probability when k is 1 we know he can choose 8 directions
and probabilty is 1 at that time so we explore all 8 possibility and get the probability and store the
computations in cache to get probability when we need it to save recursive calls.
*/

class Solution {
public:
    double cache[26][26][101];

    double getProbability(int r,int c,int k,int n){
        if(r<0 || c<0 || r>=n || c>=n)
            return 0;
        
        if(k == 0) return 1;

        if(cache[r][c][k]) return cache[r][c][k];

        double probability = 0;
        probability+=getProbability(r-2,c-1,k-1,n);
        probability+=getProbability(r-2,c+1,k-1,n);
        probability+=getProbability(r-1,c+2,k-1,n);
        probability+=getProbability(r+1,c+2,k-1,n);
        probability+=getProbability(r+2,c+1,k-1,n);
        probability+=getProbability(r+2,c-1,k-1,n);
        probability+=getProbability(r+1,c-2,k-1,n);
        probability+=getProbability(r-1,c-2,k-1,n);
        probability/=8;

        return cache[r][c][k] = probability;
    }

    double knightProbability(int n, int k, int row, int column) {
        return getProbability(row,column,k,n);
    }
};
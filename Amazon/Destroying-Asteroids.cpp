class Solution {
public:
    bool asteroidsDestroyed(long long int mass, vector<int>& asteroids) {
        ios_base::sync_with_stdio(false);
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();++i){
            if(mass<asteroids[i]) return false;
            mass+=asteroids[i];
        }
        return true;
    }
};
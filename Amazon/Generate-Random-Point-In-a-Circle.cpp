class Solution {
private:
    double Radius,Xc,Yc;
public:
    Solution(double radius, double x_center, double y_center) {
        Radius = radius;
        Xc = x_center;
        Yc = y_center;
    }

    double random(){
        return (double)rand() / RAND_MAX;
    }
    
    vector<double> randPoint() {
        vector<double> RandomPts(2);
        double len = sqrt(random())*Radius;
        double degree = 2 * M_PI * random();
        RandomPts[0] = Xc + len*cos(degree);
        RandomPts[1] = Yc + len*sin(degree);
        return RandomPts;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
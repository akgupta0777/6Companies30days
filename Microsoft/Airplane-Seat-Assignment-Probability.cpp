/*
Explanation:
If first person lost its ticket and picked someone else seat then all the other passenger will come and
sit on thier correct seats why ? because according to rule if correct seat is vacant then passenger will 
sit on thier respective seats. So now two cases arise when the last passenger comes 
- Everyone sits on correct seats and first person is sitting on last person seats so he has to take first
passenger seat
- Everyone including first passenger sitting on correct positions now he will sit on his correct seat

So two possiblities but have to choose one out of them. So answer is 1/2 or 0.5 for n above 1
if n==1 there is only 1 seat so no chance of getting incorrect seat so answer is 1.
*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        return 0.5;
    }
};
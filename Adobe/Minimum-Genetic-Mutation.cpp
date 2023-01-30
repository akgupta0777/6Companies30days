/*
Explanation:
We need to form mutations inside bank to get to the final needed mutation. If the mutation is not in the 
bank then we cannot mutate.We need the minimum way to reach the desired mutation. It seems like this problem
can be solved with BFS as we solve shortest path problems.

We make a queue and try to form each mutation and if it matches in bank we add it in the queue and increment
steps and when we reach the desired mutation we will return the number of steps and if not return -1.
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        vector<char> genes = {'A','C','G','T'};
        unordered_set<string> mutations(bank.begin(),bank.end());
        q.push(start);
        int steps = 0;
        int sz = 0;
        string temp;

        while(!q.empty()){
            sz = q.size();
            while(sz--){
                string current = q.front();
                q.pop();
                if(current == end){
                    return steps;
                }
                mutations.erase(current);
                for(int i=0;i<8;++i){
                    temp = current;
                    for(char gene : genes){
                        temp[i] = gene;
                        if(mutations.count(temp)){
                            q.push(temp);
                        }
                    }
                }
            }
            steps++;    
        }
        return -1;
    }
};
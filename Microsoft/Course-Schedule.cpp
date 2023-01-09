/*
Explanation:
We can solve this problem with graph theory.We can model the graph with courses as nodes and dependency
for learning that course as edges. If the graph contains a cycle then it is a dependency loop return false.
We can also solve this problem with Topological sort and BFS for finding cycles.

Algorithm:
Build the graph from the given prerequisites array.
Run a loop to process each node as starting point and try to find a cycle from that point.
If we found a cycle then return false.
If you can't find a cycle in whole graph then return true.
*/

class Solution {
public:
    vector<vector<int>> buildGraph(int num,vector<vector<int>>& prereqs){
        vector<vector<int>> graph(num);
        for(auto prereq : prereqs){
            graph[prereq[1]].push_back(prereq[0]);
        }
        return graph;
    }
    
    bool acyclic(vector<vector<int>>& graph,vector<bool>& todo,vector<bool>& visited,int node){
        
        if(todo[node]){
            return false;
        }
        if(visited[node]){
            return true;
        }
        
        visited[node] = todo[node] = true;
        for(int child : graph[node]){
            if(!acyclic(graph,todo,visited,child)){
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);
        vector<bool> todo(numCourses,false), visited(numCourses,false);
        
        for(int i=0;i<numCourses;++i){
            if(!visited[i] && !acyclic(graph,todo,visited,i)){
                return false;
            }
        }
        
        return true;
    }
};
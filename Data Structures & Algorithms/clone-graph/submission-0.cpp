/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& oldTonew){
        if(!node) return nullptr;

        if(oldTonew.count(node)){
            return oldTonew[node];
        }

        Node* copy = new Node(node->val);
        oldTonew[node] = copy;

        for(Node* neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor, oldTonew));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldTonew;
        return dfs(node, oldTonew);
    }
};

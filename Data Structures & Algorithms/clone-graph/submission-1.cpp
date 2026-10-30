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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        std::unordered_map<Node*, Node*> copies = {{node, {new Node(node->val)}}};
        std::vector<Node*> stack;
        stack.push_back(node);

        while (!stack.empty()) {
            Node* current = stack.back();
            stack.pop_back();

            for (Node* neighbor: current->neighbors) {
                if (!copies.contains(neighbor)) {
                    stack.push_back(neighbor);
                    copies[neighbor] = new Node(neighbor->val);
                }

                copies[current]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copies[node];
    }
};

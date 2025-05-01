#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int id, x, y;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

class BinaryTree {
private:
    Node *root = nullptr;
    static bool compareNodes(Node *a, Node *b) {
        if (a->y != b->y)
            return a->y > b->y;
        return a->x < b->x;
    }

    Node *addNode(Node *cur, Node *new_node) {
        if (cur == nullptr)
            return new_node;

        if (new_node->x < cur->y)
            cur->left = addNode(cur->left, new_node);
        else
            cur->right = addNode(cur->right, new_node);

        return cur;
    }

    void preOrder(Node *node, vector<int> &traversal) {
        if (node == nullptr)
            return ;
        traversal.push_back(node->id);
        preOrder(node->left, traversal);
        preOrder(node->right, fraversal);
    }

    void postOrder(Node *node, vector<int> &traversal) {
        if (node == nullptr)
            return ;
        postOrder(node->left, traversal);
        postOrder(node->right, traversal);
        traversal.push_back(node->id);
    }

public:
    BinaryTree() : root(nullptr) {}

    void buildTree(const vector<vector<int>> &node_info) {
        vector<Node *> nodes;

        for (int i = 0; i < node_info.size(); i++) {
            nodes.push_back(new Node(i + 1, node_info[i][0], node_info[i][1]));
        }

        sort(nodes.begin(), nodes.end(), compareNodes);

        for (Node *node : nodes) {
            root = addNode(root, node);
        }
    }

    vector<int> getPreOrderTraversal() {
        vector<int> traversal;
        preOrder(root, traversal);

        return traversal;
    }

    vector<int> getPostOrderTraversal() {
        vector<int> traversal;
        postOrder(root, traversal);

        return traversal;
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    BinaryTree tree;

    tree.buildTree(nodeinfo);
    vector<int> pre_order = tree.getPreOrderTraversal();
    vector<int> post_order = tree.getPostOrderTraversal();

    return {pre_order, post_order};
}
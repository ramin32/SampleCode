/**************************************************************
 * tree_max_depth.c++
 * Recursive and Iterative (BFS) max_depth c++ implementations.
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 AT gmail DOT com
 * http://raminrakhamimov.com
 **************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>


// Data member left out, for this example
struct Node {
    std::queue<const Node *>::size_type distance;
    Node *left;
    Node *right;
};

typedef std::queue<const Node *>::size_type size_type;

size_type recursive_depth(const Node *tree) {
    if(tree == 0)
        return 0;
    int left_depth = recursive_depth(tree->left);
    int right_depth =  recursive_depth(tree->right);
    return 1 + std::max(left_depth,right_depth);
}

size_type bfs_depth(Node *tree) {
    if(tree == 0)
        return 0;

    tree->distance = 1;

    std::queue<const Node *>  node_q;
    node_q.push(tree);

    size_type max_depth = 0;

    while(!node_q.empty()) {
        const Node *current_node = node_q.front();
        if(current_node->left) {
            node_q.push(current_node->left);
            size_type left_distance = current_node->distance + 1;
            current_node->left->distance = left_distance;
            max_depth = std::max(max_depth, left_distance);
        }
        if(current_node->right) {
            node_q.push(current_node->right);
            size_type right_distance = current_node->distance + 1;
            current_node->right->distance = right_distance;
            max_depth = std::max(max_depth, right_distance);
        }
        node_q.pop();
    }
    return max_depth;
}


int main() {
    Node a = {0};
    Node b = {0,&a};
    Node c = {0,&b};
    Node d = {0};
    Node e = {0,&c,&d};
    std::cout << recursive_depth(&e) << '\n';
    std::cout << bfs_depth(&e) << '\n';

}

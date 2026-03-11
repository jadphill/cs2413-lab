/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int checkAVL(struct TreeNode* node, long minVal, long maxVal) {
     if (!node) return 0;

    int leftHeight = checkAVL(node->left, minVal, node->val - 1);
    if (leftHeight == -1) return -1;

    int rightHeight = checkAVL(node->right, node->val + 1, maxVal);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return checkAVL(root, LONG_MIN, LONG_MAX) != -1;
}

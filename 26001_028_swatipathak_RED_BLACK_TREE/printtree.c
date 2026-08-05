#include "rbt.h"


#include <stdio.h>

#define SPACE_COUNT 8

void print_tree_structured(node* root, int space, char child_type) {
    if (root == NULL) {
        return;
    }

    // Increase indentation depth for the next level
    space += SPACE_COUNT;

    // 1. Process Right Subtree first (top of screen)
    print_tree_structured(root->right, space, 'R');

    // 2. Print Current Node with structural padding
    printf("\n");
    for (int i = SPACE_COUNT; i < space; i++) {
        printf(" ");
    }

    // Assign visual indicators based on the position of the child node
    if (child_type == 'R') {
        printf("");  // Branches upward to the Right child
    } else if (child_type == 'L') {
        printf("");  // Branches downward to the Left child
    }

    // Print values along with color tags ([R] = RED, [B] = BLACK)
    if (root->color == 1) { // Assuming 1 is defined as RED
        printf("%d[R]\n", root->data);
    } else {
        printf("%d[B]\n", root->data);
    }

    // 3. Process Left Subtree last (bottom of screen)
    print_tree_structured(root->left, space, 'L');
}

// Wrapper function to invoke from your main menu loop
void print_tree(REDBLACKTREE* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("The tree is currently empty.\n");
        return;
    }
    printf("\n--- Red-Black Tree Layout (Read Left to Right) ---\n");
    // Start at the root node, which has no prefix branch type ('Root' -> 'O')
    print_tree_structured(tree->root, 0, 'O');
    printf("--------------------------------------------------\n");
}

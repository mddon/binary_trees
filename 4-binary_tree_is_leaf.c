#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function to checks if a node is a leaf.
 * @node: nodes is binary trees.
 * Return: return 1 if node is a leaf, otherwise return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

#include "binary_trees.h"

/**
 * binary_tree_is_root - This function checks if a node is a root.
 * @node: nodes is binary trees.
 * Return: return 1 if node is a leaf, otherwise return 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !node->parent)
		return (1);
	return (0);
}

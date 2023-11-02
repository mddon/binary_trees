#include "binary_trees.h"

/**
 * sibling - Function that gets the sibling node to find uncle
 * @node: Gets sibling
 * Return: returns sibling of node
 */

binary_tree_t *sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	else
		return (node->parent->left);
}

/**
 * binary_tree_uncle - Function that finds the uncle of a node in a binary tree
 * @node: node to find uncle for
 * Return: returns pointer to uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (sibling(node->parent));
}

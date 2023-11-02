#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the binary tree
 * Return: The size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t size = 1;

	size += binary_tree_size(tree->right);
	size += binary_tree_size(tree->left);

	return (size);
}

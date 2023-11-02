#include "binary_trees.h"

/**
 * binary_tree_is_full - Function that checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree.
 * Return: returns 1 if tree is full or return 0 in otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}

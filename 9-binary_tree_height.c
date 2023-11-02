#include "binary_trees.h"

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Root node to calculate height from
 *
 * Return: Size_t representing height, 0 on failure or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t right_height = 0;
	size_t left_height = 0;

	if (tree->right)
		right_height += 1 + binary_tree_height(tree->right);

	if (tree->left)
		left_height += 1 + binary_tree_height(tree->left);

	if (left_height > right_height)
		return (left_height);

	else
		return (right_height);
}

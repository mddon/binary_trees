#include "binary_trees.h"

/**
 * tree_is_perfect - Determines if a tree is perfect
 * @tree: Tree to check for perfection
 * Return: 0 if it's not perfect, otherwise the tree's level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_levels = 0, right_levels = 0;

	if (tree->left && tree->right)
	{
		left_levels = 1 + tree_is_perfect(tree->left);
		right_levels = 1 + tree_is_perfect(tree->right);
		if (right_levels == left_levels && right_levels != 0 && left_levels != 0)
			return (right_levels);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect
 * @tree: Tree to check for perfection
 * Return: 1 if it's perfect, 0 if it's not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int is_perfect = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		is_perfect = tree_is_perfect(tree);
		if (is_perfect != 0)
		{
			return (1);
		}
		return (0);
	}
}

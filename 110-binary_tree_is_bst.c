#include "binary_trees.h"
/**
 * check_sub_tree_Left - Function that checks if all nodes are smaller than
 * the root specified
 * @node: node to verify condition
 * @max: value to compare
 * Return: return 1 if all nodes are smaller or equal or return 0 if not
 */
int check_left(const binary_tree_t *node, int max)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
		return (1);
	}

	else
	{
		if (node->n >= max)
			return (0);
		left = check_left(node->left, max);
		right = check_left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - Function that checks if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_right(const binary_tree_t *node, int min)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
		return (1);
	} 

	else
	{
		if (node->n <= min)
			return (0);
		left = check_right(node->left, min);
		right = check_right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - Function that says if a tree is a bst or not
 * @tree: node that point to the tree to check
 * Return: return 1 if it is a BST or return 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_ret = 2, right_ret = 2, value = 0;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (tree->left && tree->left->n < tree->n)
	{
		value = check_left(tree->left, tree->n);
		if (value == 0)
			return (0);
		left_ret = binary_tree_is_bst(tree->left);
	}

	if (tree->right && tree->right->n > tree->n)
	{
		value = check_right(tree->right, tree->n);
		if (value == 0)
			return (0);
		right_ret = binary_tree_is_bst(tree->right);
	}

	if (left_ret != 2 || right_ret != 2)
	{
		if (left_ret == 0 || right_ret == 0)
			return (0);
	}

	return (1);
}

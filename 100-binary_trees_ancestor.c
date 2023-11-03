#include "binary_trees.h"

/**
 * find_common_ancestor - Locates the common ancestor of two nodes
 * @node1: First node
 * @node2: Second node
 * Return: The node of the common ancestor
 */
binary_tree_t *find_common_ancestor(const binary_tree_t *node1, const binary_tree_t *node2)
{
	binary_tree_t *ances1, *ances2;

	if (!node1 || !node2)
		return (NULL);

	if (node1 == node2)
		return ((binary_tree_t *)node1);

	ances1 = node1->parent;
	ances2 = node2->parent;

	if (ances1 == NULL || node1 == ances2 || (!ances1->parent && ances2))
	{
		return (find_common_ancestor(node1, ances2));
	}
	else if (ances2 == NULL || ances1 == node2 || (!ances2->parent && ances1))
	{
		return (find_common_ancestor(ances1, node2));
	}

	return (find_common_ancestor(ances1, ances2));
}

/**
 * binary_trees_ancestor - Finds the ancestor of two nodes
 * @first: First node
 * @second: Second node
 * Return: The node of the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	return (find_common_ancestor(first, second));
}

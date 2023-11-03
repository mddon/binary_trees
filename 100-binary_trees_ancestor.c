#include "binary_trees.h"

/**
 * find_common_ancestor - Locates the common ancestor of two nodes
 * @node1: First node
 * @node2: Second node
 * Return: The node of the common ancestor
 */
binary_tree_t *find_common_ancestor(const binary_tree_t *node1,
									const binary_tree_t *node2)
{
	binary_tree_t *ancestor1, *ancestor2;

	if (!node1 || !node2)
		return (NULL);

	if (node1 == node2)
		return ((binary_tree_t *)node1);

	ancestor1 = node1->parent;
	ancestor2 = node2->parent;

	if (ancestor1 == NULL || node1 == ancestor2 || (!ancestor1->parent && ancestor2))
		return (find_common_ancestor(node1, ancestor2));
	else if (ancestor2 == NULL || ancestor1 == node2 || (!ancestor2->parent && ancestor1))
		return (find_common_ancestor(ancestor1, node2));

	return (find_common_ancestor(ancestor1, ancestor2));
}

/**
 * binary_trees_ancestor - Finds the ancestor of two nodes
 * @first: First node
 * @second: Second node
 * Return: The node of the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	return (find_common_ancestor(first, second));
}

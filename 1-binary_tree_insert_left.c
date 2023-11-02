#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child.
 * @parent: A pointer to the node to insert the left child in.
 * @value: The value to store in the node.
 * Return: A pointer to the created node or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL || value == '\0')
		return (NULL);

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		new_node->left->parent = new_node;
	}

	parent->left = new_node;
	return (new_node);
}

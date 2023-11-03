#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Tree to traverse
 * Return: The height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree)
	{
		do {
			left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		} while (0);
	}

	return ((left > right) ? left : right);
}

/**
 * binary_tree_depth - Depth of specified node from root
 * @tree: Node to check the depth
 * Return: 0 if it is the root or the number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list from the depth level and node
 * @head: Pointer to head of linked list
 * @tree: Node to store
 * @level: Depth of node to store
 * Return: Nothing
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *newnode, *auxnode;

	newnode = malloc(sizeof(link_t));
	if (newnode == NULL) {
		return;
	}
	newnode->n = level;
	newnode->node = tree;
	if (*head == NULL) {
		newnode->next = NULL;
		*head = newnode;
	} else {
		auxnode = *head;
		do {
			while (auxnode->next != NULL)
			{
				auxnode = auxnode->next;
			}
		} while (0);
		newnode->next = NULL;
		auxnode->next = newnode;
	}
}

/**
 * recursion - Traverses the complete tree and stores each node
 * in the linked_node function
 * @head: Pointer to head of linked list
 * @tree: Node to check
 * Return: Nothing, it affects the pointer
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Prints the nodes element in a level-order
 * @tree: Root node
 * @func: Function to use
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *auxnode;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	} else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		do {
			auxnode = head;
			do {
				if (count == auxnode->n) {
					func(auxnode->node->n);
				}
				auxnode = auxnode->next;
			} while (auxnode != NULL);
			count++;
		} while (count <= height);
		while (head != NULL) {
			auxnode = head;
			head = head->next;
			free(auxnode);
		}
	}
}

#include "binary_trees.h"

/**
 * *binary_tree_node_s - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, NULL on failure
 */
binary_tree_t *binary_tree_node_s(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	tmp = malloc(sizeof(binary_tree_t));
	if (tmp == NULL)
		return (NULL);
	if (tmp != NULL)
	{
		if (!parent)
			tmp->parent = NULL;
		else
			tmp->parent = parent;
		tmp->n = value;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	return (tmp);
}
/**
 * *binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);
	temp = binary_tree_node_s(parent, value);
	if (temp == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		parent->left->parent = temp;
		temp->left = parent->left;
	}
	parent->left = temp;
	return (temp);
}

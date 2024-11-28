
#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 * Return: pointer to the root node of the tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	tree = recursive_avl(tree, array, 0, size - 1);

	return (tree);
}

/**
 * recursive_avl - builds an AVL tree from a sorted array recursively
 * @tree: pointer to the parent node currently being generated
 * @array: pointer to the first element of the array
 * @start: the beggining index to the portion of the array currently being
 * worked on
 * @end: the ending index to the portion of the array currently being worked on
 * Return: pointer to the node being worked on or NULL
 */
avl_t *recursive_avl(avl_t *tree, int *array, int start, int end)
{
	int mid;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(tree, array[mid]);

	if (!root)
		return (NULL);

	root->left = recursive_avl(root, array, start, mid - 1);
	root->right = recursive_avl(root, array, mid + 1, end);

	return (root);
}

/**
 * create_node - creates a node for the AVL tree
 * @parent: pointer to the parent of the node being created
 * @n: number to set to the node's value
 * Return: pointer to the created node or NULL on failure to create it
 */
avl_t *create_node(avl_t *parent, int n)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;

	return (node);
}

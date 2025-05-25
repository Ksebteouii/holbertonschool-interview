#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_height - Gets the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree
 */
static size_t get_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * get_last_node - Gets the last node in level order
 * @root: Pointer to the root node
 * Return: Pointer to the last node
 */
static heap_t *get_last_node(heap_t *root)
{
	size_t height, i;
	heap_t *node;

	if (!root)
		return (NULL);

	height = get_height(root);
	for (i = 0; i < height; i++)
	{
		node = root;
		while (node)
		{
			if (!node->left)
				return (node);
			if (!node->right)
				return (node);
			node = node->right;
		}
	}
	return (NULL);
}

/**
 * swap_nodes - Swaps two nodes in a binary heap
 * @node1: First node
 * @node2: Second node
 */
static void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Maintains the Max Heap property by swapping nodes upward
 * @node: Node to heapify
 */
static void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = get_last_node(*root);
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	heapify_up(new_node);

	return (new_node);
} 
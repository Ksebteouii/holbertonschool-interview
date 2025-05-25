#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	heap_t **queue;
	size_t front = 0, rear = 0, size = 1024;

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

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
	{
		free(new_node);
		return (NULL);
	}

	queue[rear++] = *root;

	while (front < rear)
	{
		parent = queue[front++];
		if (!parent->left || !parent->right)
			break;
		queue[rear++] = parent->left;
		queue[rear++] = parent->right;
	}
	free(queue);

	new_node->parent = parent;
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
} 
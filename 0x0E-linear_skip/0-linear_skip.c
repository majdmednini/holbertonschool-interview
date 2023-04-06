#include "search.h"

/**
 * linear_skip - searches for a value in a sorted sk list of integers.
 * @list: pointer to the head of the sk list to search in
 * @value: value to search for
 *
 * Return: value
**/
skiplist_t *search_skip(skiplist_t *mainnode, skiplist_t *finalnode, int value)
{
	char *format = "Value found between indexes [%li] and [%li]\n";
	char *fmt = "Value checked at index [%li] = [%i]\n";

	printf(format, mainnode->index, finalnode->index);
	while (mainnode != finalnode->next)
	{
		printf(fmt, mainnode->index, mainnode->n);
		if (value == mainnode->n)
			return (mainnode);
		mainnode = mainnode->next;
	}
	return (NULL);
}
/**
 * linear_skip - search for a number in a linear skip
 * @head: list of type skiplis_t
 * @value: value to search into list
 * Return: NULL or node contain to value
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *mainnode, *finalnode;
	char *format = "Value checked at index [%li] = [%i]\n";

	if (!head)
		return (NULL);
	finalnode = head;
	while (finalnode && finalnode->next && finalnode->n < value)
	{
		mainnode = finalnode;
		if (!finalnode->express)
		{
			while (finalnode->next)
				finalnode = finalnode->next;
			continue;
		}
		else
			finalnode = finalnode->express;
		printf(format, finalnode->index, finalnode->n);
	}
	return (search_skip(mainnode, finalnode, value));
}
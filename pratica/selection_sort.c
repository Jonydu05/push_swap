static int len(int *array)
{
		int	size;
		int	i;

		i = 0;
		size = 0;
		while (array[i])
		{
				size++;
				i++;
		}
		return (size);
}

static void	selection_sort(int *array)
{
		int	i;		
		int	j;
		int	min_index;
		int	n = len(array);
		int	aux;
		i = 0;
		while (i < n - 1)
		{
				min_index = i;
				j = i;
				while (j < n)
				{
						if (array[j] < array[min_index])
								min_index = j;
						j++;
				}
				if (array[i] > array[min_index])
				{
						aux = array[i];
						array[i] = array[min_index];
						array[min_index] = aux;
				}
				i++;
		}
}

#include <stdio.h>
int	main(void)
{
		int	array[] = {4, 10, 1};
		printf("%d", len(array));
		selection_sort(array);
		printf("\n\n");
		for (int i = 0; i < 3; i++)
				printf("%d\n", array[i]);
		return (0);
}

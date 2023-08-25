#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

// Reversing a string
void reverse(char **str, int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

int next_permutation(int n, char **s)
{
    /**
    * Complete this method
    * Return 0 when there is no next permutation and 1 otherwise
    * Modify array s to its next permutation
    */
    
    int i, j;


    for (i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            // s[i] < s[i+1]
            break;
        }
    }

    // If all permutations are done
    if (i == -1) {
        return 0;
    }

    for (j = n - 1; j > i; j--) {
        // s[j] > s[i]
        if (strcmp(s[j], s[i]) > 0) {
            break;
        }
    }

    // Swap s[i] and s[j]
    swap(&s[i], &s[j]);

    
    reverse(s, i + 1, n - 1);

    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;


double area(triangle *t)
{
    double s = (t->a + t->b + t->c) / 2.0;
    return sqrt(s * (s - t->a) * (s - t->b) * (s - t->c));
}

void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (area(&tr[j]) > area(&tr[j + 1])) {
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}


int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
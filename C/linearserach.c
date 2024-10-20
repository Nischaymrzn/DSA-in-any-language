#include<stdio.h>
int sequential_search(int[], int, int);
void main() {
	int x[20], i, n, p, key;
	printf("Enter the number of element:");
	scanf("%d", &n);
	printf("\n Enter %d elements:", n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	printf("Enter the element to be search:");
	scanf("%d", &key);
	p = sequential_search(x, n, key);
	if (p == -1)
		printf("Number not found.");
	else
		printf("%d is found at location %d", key, p+1);
}
int sequential_search(int a[], int n, int k) {
	int i;
	for (i = 0; i < n; i++) {
		if (k == a[i])
			return (i);
	}
	return (-1);
}


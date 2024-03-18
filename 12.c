#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int create(int num);
void linear_prob(int a[MAX], int key, int num);
void display(int a[MAX]);

int main() {
    int a[MAX], num, key, i;
    int ans;

    printf("Collision handling by linear probing\n");

    for (i = 0; i < MAX; i++)
        a[i] = -1;

    do {
        printf("\nEnter the four digit number: ");
        scanf("%d", &num);

        key = create(num);
        linear_prob(a, key, num);

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &ans);
    } while (ans == 1);

    display(a);

    return 0;
}

int create(int num) {
    int key;
    key = num % MAX;
    return key;
}

void linear_prob(int a[MAX], int key, int num) {
    int i, index;
    index = key;

    while (a[index] != -1) {
        index = (index + 1) % MAX;
        if (index == key) {
            printf("\nHash table is full\n");
            display(a);
            exit(1);
        }
    }

    a[index] = num;
}

void display(int a[MAX]) {
    printf("\nThe hash table is:\n");
    printf("Key / Index\tEmployee ID\n");
    printf("...........................................................\n");

    for (int i = 0; i < MAX; i++) {
        if (a[i] != -1)
            printf("%d\t\t%d\n", i, a[i]);
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int next_permutation(int n, char **s) {
    int k = 0, l = 0, check = 0;
    for (int i = 0; i < n - 1; i++) 
        if (strcmp(s[i], s[i+1]) < 0) {
            k = i;
            check = 1;
        }

    if (check == 0)
        return 0;

    for (int i = k; i < n - 1; i++)
        if (strcmp(s[k], s[i+1]) < 0)
            l = i + 1;

    char *temp = s[l];
    s[l] = s[k];
    s[k] = temp;

    for (int i = 1; i < (n - k) / 2 + 1; i++) {
        char *temp = s[n - i];
        s[n - i] = s[k + i];
        s[k + i] = temp;
    }

    return 1;
}

int main() {
    char *s[] = {"a", "bc", "bc", "bc"};
    int n = 4;

    do{
        for (int i = 0; i < n; i++)
            printf("%s ", s[i]);
        printf("\n");
    }while(next_permutation(n, s));

    printf("End of Program\n");
}

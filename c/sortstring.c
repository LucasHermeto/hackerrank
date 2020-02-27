#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b) > 0 ? 1 : 0);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return (strcmp(a, b) > 0 ? 0 : 1);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i, j, dA = 0, dB = 0;
    for (i = 0; i < strlen(a); i++)
        for (j = i + 1; j < strlen(a); j++)
            if (a[i] != a[j])
                dA++;
   for (i = 0; i < strlen(b); i++) 
        for (j = i + 1; j < strlen(b); j++)
            if (b[i] != b[j])
                dB++;

    return dA == dB ? lexicographic_sort(a, b) : 0;
}

int calcDistc(const char *a) {
    int dist = 0;

    while (*a != '\0') {
        if (!strchr(a + 1, *a))
            dist++;
        a++;
    }
    return dist;
}

int sort_by_number_of_distinct_characters2(const char* a, const char* b) {
    int test = calcDistc(a) - calcDistc(b);
    return test ? test : lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int test = strlen(a) - strlen(b);
    return test ? test : lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    // Bubble Sort
    int i, j;
    for (i = 0; i < len - 1; i++) 
        for (j = 0; j < len - 1 - i; j++) 
            if (cmp_func(arr[j], arr[j+1]) > 0) {
                char *tmp_str = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp_str;
            }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
    
    string_sort(arr, n, sort_by_number_of_distinct_characters2);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}

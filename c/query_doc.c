#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return *(*(*(document + k) + m) + n);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return *(*(document + k) + m);
}

char*** kth_paragraph(char**** document, int k) {
    return *(document + k);
}


char**** get_document(char* text) {
    // Initialize document
    char ****document = (char ****) malloc(MAX_PARAGRAPHS * sizeof(char ***));  // Paragraph
    for (int i = 0; i < MAX_PARAGRAPHS; i++) {
        *(document + i) = (char ***) malloc(10 * sizeof(char **));              // Sentence
       for (int j = 0; j < 10; j++) {
           *(*(document + i) + j) = (char **)malloc(50 * sizeof(char *));       // Words
           for (int k = 0; k < 50; k++)
                *(*(*(document + i) + j) + k) = (char *) malloc(32 * sizeof(char));// Characters
        }
    }

    int i = 0, i_word = 0, n_paragraph = 0, n_sentence = 0, n_word = 0;
    char next = *(text);
    while (next != '\0') {
        if (next == ' ') {
            // End of Word
            n_word++, i_word = 0;
        } else if (next == '.') {
            // End of Sentence
            n_sentence++;
            n_word = 0, i_word = 0;
        } else if (next == '\n') {
            // End of Paragraph
            n_paragraph++;
            n_sentence = 0, n_word = 0, i_word = 0;
        } else {
            // Next Char
            document[n_paragraph][n_sentence][n_word][i_word++] = next;
        }
        next = *(text + ++i);
    }

    return document;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() {
    char * text = get_input_text();
    // char *text = "Lucas Faria.Hermeto.\0";

    char **** document = get_document(text);
    printf("%s", kth_word_in_mth_sentence_of_nth_paragraph(document, 0, 0, 0));
    printf("End of Program\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

// char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {}

// char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { }

// char*** kth_paragraph(char**** document, int k) {}

char**** get_document(char* text) {
    // Loop for all text
    char **** document = (char ****) malloc(MAX_PARAGRAPHS * sizeof(char ***));
    char next = *text;
    int i = -1, n_paragraph = 0;
    while(next != '\0') {
        next = *(text + ++i);

        // Loop for Paragraph
        char *** paragraph = (char ***) malloc(sizeof(char **));
        int n_sentences = 0;
        while (next != '\n' && next != '\0') {
            // Loop for Sentence
            char ** sentence = (char **) malloc(sizeof(char*));
            int n_word = 0;
            while (next != '.' && next != '\0') {
                // Loop for word
                char *word = (char*) malloc(32 * sizeof(char));
                int n_char = 0;
                while (next != ' ' && next != '\0') {
                    // Remove last dot '.'
                    if (next == '.') break;
                    if (next != '\n') *(word + n_char++) = next;

                    next = *(text + ++i);
                }
                word = (char*) realloc(word, n_char * sizeof(char));
                printf("W: %s - S: %d\n", word, n_sentences);

                // Add word to sentence
                *(sentence + n_word++) = word;
                sentence = (char **) realloc(sentence, (n_word+1) * sizeof(char *));

                next = *(text + ++i);
            }
            *(paragraph + n_sentences++) = sentence;
            paragraph = (char ***) realloc(paragraph, (n_sentences + 1) * sizeof(char **));

            next = *(text + ++i);
        }
        *(document + n_paragraph++) = paragraph;
    }

    printf("Procurando palavra\n");
    printf("NOME: %s", (document[0][0][0]));
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
    char *text = get_input_text();
    
    get_document(text);

    printf("\nEnd of Program\n");

    return 0;
}

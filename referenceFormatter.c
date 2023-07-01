#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

struct field{
  char journalName[BUFFER_SIZE];
  char year[BUFFER_SIZE];
  char issueNo[BUFFER_SIZE];
  char page[BUFFER_SIZE];
};

struct field f; // global variable is created because it will be used in extractJournalInfo(char* str) function

// Surnames and names of the authors can be transformed using convertAuthors function. Surnames stay same while the first letters are extracted of names.
void convertAuthors(char *str) {
  int count, comma = 0;
  
  char new_str[BUFFER_SIZE];
  memset(new_str, 0, strlen(new_str));
  const char inner_delimiters[] = ",";
  char* inner_saveptr = NULL;

  char l[5];
  
  char* inner_token = strtok_r(str, inner_delimiters, &inner_saveptr);
  while (inner_token != NULL) {
    count++;
    if(count % 2 == 0){
      strcat(new_str, inner_token);
      strcat(new_str, ", ");
    }
    else{
        l[0] = inner_token[1];
        l[1] = '.';
        l[2] = ',';
        l[3] = '\0';
        strcat(new_str, l);
    }
    inner_token = strtok_r(NULL, inner_delimiters, &inner_saveptr);
  }
    int length = strlen(new_str);
    new_str[length - 1] = '\0';
    length = strlen(new_str);
    for(int j = 0; j < length; j++){
      if(new_str[j] == 'a' && new_str[j+1] == 'n' && new_str[j+2] == 'd'){
        new_str[j+1] = '&';
        memmove(&new_str[j], &new_str[j + 1], strlen(new_str) - j);
        memmove(&new_str[j+1], &new_str[j + 1 + 1], strlen(new_str) - j + 1);
        break;
      }
    }
    strcpy(str, new_str);
    memset(new_str, 0, strlen(new_str));
}

void extractJournalInfo(char* str){
  int len = strlen(str);
  const char inner_delimiters[] = " ";
  char* inner_saveptr = NULL;
  char* inner_token = strtok_r(str, inner_delimiters, &inner_saveptr);
  strcpy(f.journalName, inner_token);
  inner_token = strtok_r(NULL, inner_delimiters, &inner_saveptr);
  strcpy(f.issueNo, inner_token);
  inner_token = strtok_r(NULL, inner_delimiters, &inner_saveptr);
  strcpy(f.year, inner_token);
  f.year[strlen(f.year) - 1] = '.';
  inner_token = strtok_r(NULL, inner_delimiters, &inner_saveptr);
  strcpy(f.page, inner_token);
  if(f.page[strlen(f.page) - 1] == '\n')
    f.page[strlen(f.page) - 1] = '\0';
}


void mlaToApa(char *filename) {
  FILE *p;
  FILE *w;
  
  w = fopen("apa.txt", "wb");
  p = fopen(filename, "rb");
  
  if (p == NULL) {
    printf("Error! File not found!");
    return;
  }

  
  char buffer[BUFFER_SIZE];

  const char outer_delimiters[] = "\"";
  
  char* token;
  
  char apa[BUFFER_SIZE];
  
  memset(apa, 0, strlen(apa));
  char* outer_saveptr = NULL;
  
  char temp_title[BUFFER_SIZE];
  
  while (fgets(buffer, BUFFER_SIZE, p) != NULL) {
    token = strtok_r(buffer, outer_delimiters, &outer_saveptr); // Holds the authors' names and surnames.
    convertAuthors(token);
    strcat(apa, token);
    
    token = strtok_r(NULL, outer_delimiters, &outer_saveptr); // Holds the article title.
    strcpy(temp_title, token);
    
    token = strtok_r(NULL, outer_delimiters, &outer_saveptr); // Holds the journal name, issue number, year of publication and page. 
    extractJournalInfo(token);
    
    strcat(apa, " ");
    strcat(apa, f.year);
    strcat(apa, " ");
    strcat(apa, temp_title);
    strcat(apa, " ");
    strcat(apa, f.journalName);
    strcat(apa, ", ");
    strcat(apa, f.issueNo);
    strcat(apa, ", ");
    strcat(apa, f.page);
    strcat(apa, "\n");
    fprintf(w, "%s", apa);
    
    memset(apa, 0, strlen(apa));  // clear the apa to get the next buffer
  }
}  


int main(void) {
  char *filename = "mla.txt";
  mlaToApa(filename);
  return 0;
}
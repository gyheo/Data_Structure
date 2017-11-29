#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3
#define BUFFER_SIZE 50

// 전역변수(global variable) 선언
// 외부에 선언된 변수
// * data 영역에 저장됨
// char *names[CAPACITY];
// char *numbers[CAPACITY];
char ** names;
char ** numbers;

int capacity = INIT_CAPACITY;
int n = 0;

char delim[] = " ";


void init_directory();
void process_command();
void read();
void add();
void reallocate();
void find();
void status();
void del();
void save();

int main(void){
    // 지역변수(local variable) 선언
    // * stack 영역에 저장됨
    init_directory();
    process_command();

    return 0;
}

void init_directory(){
  names = (char**)malloc(INIT_CAPACITY * sizeof(char *));
  numbers = (char**)malloc(INIT_CAPACITY * sizeof(char *));
}

int read_line(char str[], int limit){
  int ch, i = 0;

  while((ch == getchar()) != '\n'){
    if(i < limit - 1){
      str[i++] = ch;
    }
  }

  str[i] = '\0';

  return i;
}

void process_command() {
  char command_line[BUFFER_SIZE];
  char *command, *argument1, *argument2;

  while(1){
    printf(" $ ");

    if (read_line(command_line, BUFFER_SIZE) <= 0){
      continue;
    }

    command = strtok(command_line, delim);
    if (command == NULL){
      continue;
    }

    if(strcmp(command, "read") == 0){
      argument1 = strtok(NULL, delim);

      if(argument1 == NULL){
        printf("File name required. \n");
        continue;
      }

      read(argument1);
    }

    else if(strcmp(command, "add") == 0){
      argument1 = strtok(NULL, delim);
      argument2 = strtok(NULL, delim);

      if(argument1 == NULL || argument2 == NULL){
        printf("Invalid arguments. \n");
        continue;
      }

      add(argument1, argument2);

      printf("%s was added successfully. \n", argument1);
    }

    else if(strcmp(command, "find") == 0){
      argument1 = strtok(NULL, delim);

      if(argument1 == NULL){
        printf("Invalid arguments. \n");
        continue;
      }

      find(argument1);
    }

    else if(strcmp(command, "status") == 0){
      status();
    }

    else if(strcmp(command, "delete") == 0){
      argument1 = strtok(NULL, delim);

      if(argument1 == NULL){
        printf("Invalid arguments. \n");
        continue;
    }
    remove(argument1);
    }

    else if(strcmp(command, "save") == 0){
      argument1 = strtok(NULL, delim);
      argument2 = strtok(NULL, delim);

      if(argument1 == NULL || strcmp("as", argument1) != 0 || argument2 == NULL){
        printf("Invalid arguments. \n");
        continue;
    }
    save(argument1);
    }

    else if(strcmp(command, "exit") == 0){
      break;
    }
  }
}

void read(){
  char fileName[BUFFER_SIZE];
  char buf1[BUFFER_SIZE];
  char buf2[BUFFER_SIZE];

  scanf("%s", fileName);

  // 파일을 열고 읽을 때 (r)
  FILE *fp = fopen(fileName, "r");
  if(fp == NULL){
      printf("Open failed. \n");
      return ;
  }

  while((fscanf(fp, "%s", buf1) != EOF)){
      fscanf(fp, "%s", buf2);
      names[n] = strdup(buf1);
      numbers[n] = strdup(buf2);
      n++;
  }

  // 반드시 닫아주는 과정 추가!
  fclose(fp);
}

void add(char *name, char *number){
  if(n >= capacity){
    reallocate();
  }

  int i = n - 1;
  while(i >= 0 && strcmp(names[i], name) > 0){
    names[i+1] = names[i];
    numbers[i+1] = numbers[i];
    i--;
  }

  names[i+1] = strdup(name);
  numbers[i+1] = strdup(number);

  n++;
  // printf("%s was added successfully! \n", buf1);
}

void find(char * name){
  int index = search(name);
  if(index == -1){
    // printf("No person named \'%s\' exists \n", buf);
  }
  else{
    printf("%s\n", numbers[index]);
  }
}

int search(char *name){
  int i;
  for(i=0; i<n; i++){
    if(strcmp(name, names[i]) == 0){
      return i;
    }
  }

  return -1;
}

void status(){
  int i = 0;
  for(i=0; i<n; i++){
    printf("%s  %s \n", names[i], numbers[i]);
  }
  printf("Total %d persons \n", n);
}

void save(char *fileName){
  int i;
  // 파일을 저장할 경우에는 (w)
  FILE *fp = fopen(fileName, "w");
  if(fp == NULL){
    printf("Open failed. \n");
    return ;
  }

  for(i=0; i<n; i++){
    fprintf(fp, "%s %s\n", names[i], numbers[i]);
  }

  fclose(fp);
}

void del(char *name){
  int i = search(name);
  if(i == -1){
    printf("No person named \'%s\' exists. \n", name);
    return;
  }

  int j = i;
  for(; j < n - 1; j++){
    names[j] = names[j+1];
    numbers[j] = numbers[j+1];
  }
  n--;
  printf("\'%s\' was deleted successfully \n", name);
}

void reallocate(){
  int i;

  capacity *= 2;
  char **tmp1 = (char **)malloc(capacity * sizeof(char *));
  char **tmp2 = (char **)malloc(capacity * sizeof(char *));

  for(i = 0; i < n; i++){
    tmp1[i] = names[i];
    tmp2[i] = numbers[i];
  }

  free(names);
  free(numbers);

  names = tmp1;
  numbers = tmp2;
}

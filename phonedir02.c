#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

// 전역변수(global variable) 선언
// 외부에 선언된 변수
// * data 영역에 저장됨
char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0;

void read();
void add();
void find();
void status();
void del();
void save();

int main(void){
    // 지역변수(local variable) 선언
    // * stack 영역에 저장됨
    char command[BUFFER_SIZE];
    while(1){
        printf("$ ");
        scanf("%s", command);

        // read, save 기능 추가
        if(strcmp(command, "read") == 0){
            read();
        }
        else if(strcmp(command, "add") == 0){
            add();
        }
        else if(strcmp(command, "find") == 0){
            find();
        }
        else if(strcmp(command, "status") == 0){
            status();
        }
        else if(strcmp(command, "del") == 0){
            del();
        }
        else if(strcmp(command, "save") == 0){
            save();
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

void add(){
  char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
  scanf("%s", buf1);
  scanf("%s", buf2);

  int i = n - 1;
  // * bubble sort와 비슷하게 정렬
  // 영문 순서를 사전식으로 정렬하기 위해 필요
  while(i>=0 && strcmp(names[i], buf1) > 0){
    names[i+1] = names[i];
    numbers[i+1] = numbers[i];
    i--;
  }

  names[i+1] = strdup(buf1);
  numbers[i+1] = strdup(buf2);

  n++;
  printf("%s was added successfully! \n", buf1);
}

void find(){
  char buf[BUFFER_SIZE];
  scanf("%s", buf);

  int i;
  for(i=0; i<n; i++){
    if(strcmp(buf, names[i]) == 0){
      printf("%s\n", numbers[i]);
      return ;
    }
  }

  printf("No person named \'%s\' exists \n", buf);
}

void status(){
  int i = 0;
  for(i=0; i<n; i++){
    printf("%s  %s \n", names[i], numbers[i]);
  }
  printf("Total %d persons \n", n);
}

void save(){
  int i;
  char fileName[BUFFER_SIZE];
  char tmp[BUFFER_SIZE];

  scanf("%s", tmp);
  scanf("%s", fileName);
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

void del(){
  char buf[BUFFER_SIZE];
  scanf("%s", buf);

  int i;
  for(i=0; i<n; i++){
    if(strcmp(buf, names[i]) == 0){
      names[i] = names[n-1];
      numbers[i] = numbers[n-1];
      // 인원 감소 -1
      n--;
      printf("\'%s\' was deleted successfully! \n", buf);
      return;
    }
  }

  printf("No person named \'%s\' exists \n", buf);
}

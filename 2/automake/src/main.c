#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char needChar(int mod){
  char t[3];
  while(t[0] < 49 || t[0] > 55-mod){
 	fgets(t, 3, stdin);
 	if (t[0] < 49 || t[0] > 55-mod) printf("Такое значение не подходит попробуйте ещё раз\n");
  }
  return t[0];
}

void crackEnt(char *str, int mod){
	if(mod == 1){
		for (size_t i = 0; i < 512; i++) {
	      if (str[i] == '\n') {
	        str[i] = ';';
	        strcat(str, " ");
	        break;
	      }	
	    }
	}
	else if(mod == -1){
		for (size_t i = 0; i < 512; i++) {
	      if (str[i] == '\n') {
	        str[i] = '\0';
	        break;
	      }	
	    }	
	}
}

void main() {
  node head = createNode();
  char string1[512];
  char string2[512];
  char string3[512];
  char string4[512];
  char string5[512];
  char string6[512];
  char file[512];
  int check = 1;
  char inp[512];
  while (check) {
    printf("Выберете необходимую функцию:\n\n1. Добавить\n2. Удалить\n3. Изменить\n4. Вывести список\n5. Выход\n6. Загрузить из файла\n7. Загрузить в файл\n\n");

    //printf("%d((((((sxsxsxsxxsxs\n", needChar());
    switch (needChar(0)) {
      /*Добавление эелемента в БД*/
      case '1':
        printf("\nВведите название: ");
        fgets(string1, 512, stdin);

        printf("\nВведите модель: ");
        fgets(string2, 512, stdin);

        printf("\nВведите разработчика: ");
        fgets(string3, 512, stdin);

        printf("\nВведите предприятие: ");
        fgets(string4, 512, stdin);

        printf("\nВведите стоимость: ");
        fgets(string5, 512, stdin);

        printf("\nВведите тип: ");
        fgets(string6, 512, stdin);

        crackEnt(string1, 1);
        crackEnt(string2, 1);
        crackEnt(string3, 1);
        crackEnt(string4, 1);
        crackEnt(string5, 1);

        strcat(string1, string2);
        strcat(string1, string3);
        strcat(string1, string4);
        strcat(string1, string5);
        strcat(string1, string6);
        printf("\n%s\n\n", string1);
        addNode(head, string1);
        break;
      /*Удаление*/
      case '2':
        {
        int i = 0;
        printf("Выберите элемент: ");
	    scanf("%d", &i);
        while(i > HowMuchNode(head) || i < 1){
	      printf("Выберите элемент в доступном диапазоне: ");
	      scanf("%d", &i);
    	}
        head = DelByIndex(i, head);
        }
        break;
      /*Изменени;*/
      case '3':
        printf("\nВведите номер записи: ");
        int x = 0;
        scanf("%d", &x);
        getchar();
        printf("\nВведите название: ");
        fgets(string1, 512, stdin);
        printf("Выберите тип вещания:\n\n1. обычный\n2. HD\n\n");
        switch (needChar(5)) {
          case '1':
            strcpy(string2, "обычный");
            break;
          case '2':
            strcpy(string2, "HD");
            break;
        }

        printf("Выберите флаг общедоступности:\n\n1. Да\n2. Нет\n\n");
        switch (needChar(5)) {
          case '1':
            strcpy(string3, "Да");
            break;
          case '2':
            strcpy(string3, "Нет");
            break;
        }

        for (size_t i = 0; i < 512; i++) {
          if (string1[i] == '\n') {
            string1[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string2[i] == '\n') {
            string2[i] = ' ';
            break;
          }
        }
        strcat(string1, string2);
        strcat(string1, string3);
        printf("\n%s\n\n", string1);
        strcpy(NodeByIndex(x, head)->data, string1);
        break;
      /*Вывод списка*/
      case '4':
        {
          node n = head;
          n = n->next;
          int i = 1;
          while (n != NULL) {
            printf("%d. %s\n",i++ , n->data);
            n = n->next;
          }
          printf("\n");
        }
        break;
      /*Закрытие программы*/
      case '5':
        return;
        break;
      case '6':
      	printf("Введите имя файла без расширения: ");
      	fgets(file, 512, stdin);
      	crackEnt(file, -1);
      	strcat(file, ".bd");

      	FILE *fp2 = fopen(file, "rt");
      	
      	char str[512];
      	while(fgets(str, 512, fp2) != NULL){
      		addNode(head, str);
      	}

      	fclose(fp2);
      	printf("\n");
      	break;
      case '7':
      	printf("Введите имя файла без расширения: ");
      	fgets(file, 512, stdin);
      	crackEnt(file, -1);
      	strcat(file, ".bd");

      	FILE *fp = fopen(file, "a+t");
      	
      	if(head->data != ""){
      		node tmp = head;
      		while(tmp->next != NULL){
      			fputs(tmp->data, fp);
      			tmp = tmp->next;
      		}
      		fputs(tmp->data, fp);
      	}

      	fclose(fp);
      	printf("\n");
      	break;
    }
  }
}
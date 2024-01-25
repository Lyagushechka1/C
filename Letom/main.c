#include <stdio.h>

/*
/Users/gleb/Desktop/a.txt
*/

int main(void)
{
    char line[255];
    int choice;
    char filename[100];
    printf("Введите имя файла для сохранения текста: ");
    scanf("%s", filename);

    while (choice == 4)
    {
        printf("%s", "Выберите операцию\n1 - Чтение\n2 - Ввод\n3 - Удаление Файла\n4 - Выход\nВыбор: ");
        scanf("%d", &choice);
        //-----------------------Funcions-----------------------------//
        if (choice > 3)
        {
            perror("Некорренктный вариант!\n");
        }
        //--------------------------1---------------------------------//
        else if (choice == 1)
        {
            FILE *file = fopen(filename, "r");
            fgets(line, 255, file);
            printf("%s\n", line);
        }
        //--------------------------2---------------------------------//
        else if (choice == 2)
        {
            char text[1000];
            FILE *file1 = fopen(filename, "w");
            printf("%s", "Ведите текст который хотите видить в файле: ");
            scanf("%s", text);
            fprintf(file1, "%s", text);
            fclose(file1);
        }
        //--------------------------3---------------------------------//
        else if (choice == 3)
        {
            if (remove(filename) == 0)
            {
                printf("Файл успешно удален.\n");
            }
            else
            {
                perror("Ошибка при удалении файла");
            }
        }
        //--------------------------4---------------------------------//
        else if (choice == 4)
        {
            break;
        }
        return 0;
    }
}
/*
 if(remove(file_name) == 0){
     printf("Файл успешно удален.\n");
 }else {
     perror("Ошибка при удалении файла");
 }
*/

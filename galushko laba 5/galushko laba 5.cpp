/******************************************************************************
Галушко Диана Юрьевна
КТбо1-2
Лабораторная работа №5 «Файлы данных»
Вариант № 7
Задание: Написать программу, которая записывает с клавиатуры в файл структуру согласно выданному варианту задания.
         В качестве разделителя полей структуры использовать символ табуляции. В программе реализовать:
         а) дополнение  существующего массива структур новыми структурами;
         б) поиск структуры с заданным значением выбранного элемента;
         в) вывод на экран содержимого массива структур;
         г) упорядочение массива структур по заданному полю (элементу), например государство по численности.
         Поля структуры: марка, цвет, серийный номер, регистрационный номер, количество дверей, год выпуска, тип автомобиля (легковой, грузовой, джип, автобус), цена
*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
const int all = 10;
const int length = 50;

struct car {
    char mark[length];
    char color[length];
    char num[length];
    char regnum[length];
    int doors;
    int year;
    char type[length];
    int price;
};

typedef car* carp;
car list[all];
carp pointc[all];

int getinfo()
{
    int i, k, x;
    printf("Введите количество машин: ");
    scanf("%d", &k);
    if (k > all || k < 0)
    {
        printf("Неверное количество");
        return 0;
    }
    for (i = 0; i < k; i++)
    {
        printf("Введите марку автомобиля: ");
        fgets(list[i].mark, length, stdin);
        fgets(list[i].mark, length, stdin);
        printf("Введите цвет автомобиля: ");
        fgets(list[i].color, length, stdin);
        printf("Введите серийный номер автомобиля: ");
        fgets(list[i].num, length, stdin);
        printf("Введите регистрационный номер автомобиля: ");
        fgets(list[i].regnum, length, stdin);
        printf("Введите количество дверей автомобиля: ");
        scanf("%d", &list[i].doors);
        printf("Введите год выпуска автомобиля: ");
        scanf("%d", &list[i].year);
        printf("Введите тип автомобиля: ");
        fgets(list[i].type, length, stdin);
        fgets(list[i].type, length, stdin);
        printf("Введите цену автомобиля: ");
        scanf("%d", &list[i].price);
        printf("\n");
        for (x = 0; list[i].mark[x] != '\n'; x++); list[i].mark[x] = '\0';
        for (x = 0; list[i].color[x] != '\n'; x++); list[i].color[x] = '\0';
        for (x = 0; list[i].num[x] != '\n'; x++); list[i].num[x] = '\0';
        for (x = 0; list[i].regnum[x] != '\n'; x++); list[i].regnum[x] = '\0';
        for (x = 0; list[i].type[x] != '\n'; x++); list[i].type[x] = '\0';
    }
}

void addcar(int t)
{
    int x;
    printf("Введите марку автомобиля: ");
    fgets(list[t].mark, length, stdin);
    fgets(list[t].mark, length, stdin);
    printf("Введите цвет автомобиля: ");
    fgets(list[t].color, length, stdin);
    printf("Введите серийный номер автомобиля: ");
    fgets(list[t].num, length, stdin);
    printf("Введите регистрационный номер автомобиля: ");
    fgets(list[t].regnum, length, stdin);
    printf("Введите количество дверей автомобиля: ");
    scanf("%d", &list[t].doors);
    printf("Введите год выпуска автомобиля: ");
    scanf("%d", &list[t].year);
    printf("Введите тип автомобиля: ");
    fgets(list[t].type, length, stdin);
    fgets(list[t].type, length, stdin);
    printf("Введите цену автомобиля: ");
    scanf("%d", &list[t].price);
    printf("\n");
    for (x = 0; list[t].mark[x] != '\n'; x++); list[t].mark[x] = '\0';
    for (x = 0; list[t].color[x] != '\n'; x++); list[t].color[x] = '\0';
    for (x = 0; list[t].num[x] != '\n'; x++); list[t].num[x] = '\0';
    for (x = 0; list[t].regnum[x] != '\n'; x++); list[t].regnum[x] = '\0';
    for (x = 0; list[t].type[x] != '\n'; x++); list[t].type[x] = '\0';
}

void dataout1(FILE* f, int i)
{
    fprintf(f, "%s\t", list[i].mark);
    fprintf(f, "%s\t", list[i].color);
    fprintf(f, "%s\t", list[i].num);
    fprintf(f, "%s\t", list[i].regnum);
    fprintf(f, "%d\t", list[i].doors);
    fprintf(f, "%d\t", list[i].year);
    fprintf(f, "%s\t", list[i].type);
    fprintf(f, "%d\n", list[i].price);
}
void dataout2(FILE* f, int i)
{
    fprintf(f, "%s\t", pointc[i]->mark);
    fprintf(f, "%s\t", pointc[i]->color);
    fprintf(f, "%s\t", pointc[i]->num);
    fprintf(f, "%s\t", pointc[i]->regnum);
    fprintf(f, "%d\t", pointc[i]->doors);
    fprintf(f, "%d\t", pointc[i]->year);
    fprintf(f, "%s\t", pointc[i]->type);
    fprintf(f, "%d\n", pointc[i]->price);
}

void datashow(int i)
{
    int k = i + 1;
    printf("Марка %d машины: %s\n", k, list[i].mark);
    printf("Цвет %d машины: %s\n", k, list[i].color);
    printf("Серийный номер %d машины: %s\n", k, list[i].num);
    printf("Регистрационный номер %d машины: %s\n", k, list[i].regnum);
    printf("Количество дверей %d машины: %d\n", k, list[i].doors);
    printf("Год выпуска %d машины: %d\n", k, list[i].year);
    printf("Тип %d машины: %s\n", k, list[i].type);
    printf("Цена %d машины: %d\n", k, list[i].price);
    printf("\n");
}

void schMark(int s, FILE* f)
{
    char text[length];
    int x;
    printf("Введите значение: ");
    fgets(text, length, stdin);
    fgets(text, length, stdin);
    for (x = 0; text[x] != '\n'; x++); text[x] = '\0';
    for (int i = 0; i < s; i++)
        if (strcmp(text, list[i].mark) == 0)
            dataout1(f, i);
}

void schColor(int s, FILE* f)
{
    char text[length];
    int x;
    printf("Введите значение: ");
    fgets(text, length, stdin);
    fgets(text, length, stdin);
    for (x = 0; text[x] != '\n'; x++); text[x] = '\0';
    for (int i = 0; i < s; i++)
        if (strcmp(text, list[i].color) == 0)
            dataout1(f, i);
}

void schNum(int s, FILE* f)
{
    char text[length];
    int x;
    printf("Введите значение: ");
    fgets(text, length, stdin);
    fgets(text, length, stdin);
    for (x = 0; text[x] != '\n'; x++); text[x] = '\0';
    for (int i = 0; i < s; i++)
        if (strcmp(text, list[i].num) == 0)
            dataout1(f, i);
}

void schRegnum(int s, FILE* f)
{
    char text[length];
    int x;
    printf("Введите значение: ");
    fgets(text, length, stdin);
    fgets(text, length, stdin);
    for (x = 0; text[x] != '\n'; x++); text[x] = '\0';
    for (int i = 0; i < s; i++)
        if (strcmp(text, list[i].regnum) == 0)
            dataout1(f, i);
}

void schDoors(int s, FILE* f)
{
    int k;
    printf("Введите значение: ");
    scanf("%d", &k);
    for (int i = 0; i < s; i++)
        if (k == list[i].doors)
            dataout1(f, i);
}

void schYear(int s, FILE* f)
{
    int k;
    printf("Введите значение: ");
    scanf("%d", &k);
    for (int i = 0; i < s; i++)
        if (k == list[i].year)
            dataout1(f, i);
}

void schType(int s, FILE* f)
{
    char text[length];
    int x;
    printf("Введите значение: ");
    fgets(text, length, stdin);
    fgets(text, length, stdin);
    for (x = 0; text[x] != '\n'; x++); text[x] = '\0';
    for (int i = 0; i < s; i++)
        if (strcmp(text, list[i].type) == 0)
            dataout1(f, i);
}

void schPrice(int s, FILE* f)
{
    int k;
    printf("Введите значение: ");
    scanf("%d", &k);
    for (int i = 0; i < s; i++)
        if (k == list[i].price)
            dataout1(f, i);
}

void srtMark(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (strcmp(pointc[j]->mark, pointc[j + 1]->mark) > 0) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtColor(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (strcmp(pointc[j]->color, pointc[j + 1]->color) > 0) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtNum(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (strcmp(pointc[j]->num, pointc[j + 1]->num) > 0) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtRegnum(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (strcmp(pointc[j]->regnum, pointc[j + 1]->regnum) > 0) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtDoors(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (pointc[j]->doors > pointc[j + 1]->doors) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtYear(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (pointc[j]->year > pointc[j + 1]->year) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtType(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (strcmp(pointc[j]->type, pointc[j + 1]->type) > 0) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srtPrice(carp pointc[], int s, FILE* f)
{
    carp temp;
    int i, j;
    for (i = 0; i < s - 1; i++) {
        for (j = s - 2; j >= i; j--) {
            if (pointc[j]->price > pointc[j + 1]->price) {
                temp = pointc[j];
                pointc[j] = pointc[j + 1];
                pointc[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
        dataout2(f, i);
}

void srch(int k, FILE* f)
{
    int srchh = 1;
    while (srchh)
    {
        printf("Выберите что искать:\n");
        printf("1 - марка\n");
        printf("2 - цвет\n");
        printf("3 - серийный номер\n");
        printf("4 - регистрационный номер\n");
        printf("5 - количество дверей\n");
        printf("6 - год выпуска\n");
        printf("7 - тип машины\n");
        printf("8 - цена\n");
        printf("9 - завершение поиска.\n");
        printf("Выбранный элемент: ");
        scanf("%d", &srchh);
        printf("\n");
        switch (srchh) {
        case 1: { schMark(k, f); break; }
        case 2: { schColor(k, f); break; }
        case 3: { schNum(k, f); break; }
        case 4: { schRegnum(k, f); break; }
        case 5: { schDoors(k, f); break; }
        case 6: { schYear(k, f); break; }
        case 7: { schType(k, f); break; }
        case 8: { schPrice(k, f); break; }
        default: return;
        }
    }
}

void srt(int k, FILE* f)
{
    int srtt = 1;
    while (srtt)
    {
        printf("Выберите что сортировать:\n");
        printf("1 - марка\n");
        printf("2 - цвет\n");
        printf("3 - серийный номер\n");
        printf("4 - регистрационный номер\n");
        printf("5 - количество дверей\n");
        printf("6 - год выпуска\n");
        printf("7 - тип машины\n");
        printf("8 - цена\n");
        printf("9 - завершение поиска.\n");
        printf("Выбранный элемент: ");
        scanf("%d", &srtt);
        printf("\n");
        switch (srtt) {
        case 1: { srtMark(pointc, k, f); break; }
        case 2: { srtColor(pointc, k, f); break; }
        case 3: { srtNum(pointc, k, f); break; }
        case 4: { srtRegnum(pointc, k, f); break; }
        case 5: { srtDoors(pointc, k, f); break; }
        case 6: { srtYear(pointc, k, f); break; }
        case 7: { srtType(pointc, k, f); break; }
        case 8: { srtPrice(pointc, k, f); break; }
        default: return;
        }
        if (srtt != 0)
            fprintf(f, "%c", '\n');
    }
}

void menu(int k, FILE* f)
{
    int m = 1, i;
    while (m)
    {
        printf("Выберите опцию:\n");
        printf("1 - добавление машины;\n");
        printf("2 - поиск машины;\n");
        printf("3 - вывод на экран машин;\n");
        printf("4 - упорядочение машин;\n");
        printf("5 - завершение работы.\n");
        printf("Выбранная опция: ");
        scanf("%d", &m);
        printf("\n");
        switch (m) {
        case 1: {
            if (k >= all) { puts("Невозможно добавить машину.\n"); }
            else { addcar(k); k++; }
            break;
        }
        case 2: {
            srch(k, f);
            fprintf(f, "%c", '\n');
            break;
        }
        case 3: {
            for (i = 0; i < k; i++) { datashow(i); }
            break;
        }
        case 4: {
            for (int i = 0; i < k; i++) { pointc[i] = &list[i]; }
            srt(k, f);
            fprintf(f, "%c", '\n');
            break;
        }
        default: return;
        }
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE* f = fopen("list.txt", "w");
    if (f == NULL)
    {
        puts("Ошибка работы с файлом");
        return 0;
    }
    int k = getinfo();
    if (k == 0)
        return 0;
    menu(k, f);
    fclose(f);
    return 0;
}
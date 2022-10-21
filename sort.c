/*
Will Gonzalez
CS50AP
Cmdr. Schenk
AUG 30 2022
Sorting
*/

#include <stdio.h>
#include <string.h>
//Define creating a macro
#define TOTAL_ITEMS 10
#define TOTAL_ITEM_LEN 200

void InsertionSort(char func[TOTAL_ITEMS][TOTAL_ITEM_LEN]);

int main()
{
    //Variables
    int value;
    char strings[TOTAL_ITEMS][TOTAL_ITEM_LEN];

    printf("Enter %d strings.\n", TOTAL_ITEMS);//Prompting user for input
    for (value = 0; value < TOTAL_ITEMS; value++)
    {
        printf("Input Metal %d : ", value);
        scanf("%199s", strings[value]);     // limit the width so we don't go past the buffer
        strings[value][sizeof(strings[value]) - 1] = '\0';
    }

    InsertionSort(strings);

    printf("\n Input in order\n");
    for (value = 0; value < TOTAL_ITEMS; value++)//Printing it in order
    {
        printf("%s\n", strings[value]);
    }
}

void InsertionSort(char func[TOTAL_ITEMS][TOTAL_ITEM_LEN])
{
    for (int i = 1; i < TOTAL_ITEMS; i++)
    {
        int x = i;

        while (x > 0 && strcmp(func[x - 1], func[x]) > 0)
        {
            char var[TOTAL_ITEM_LEN];
            strncpy(var, func[x - 1], sizeof(var) - 1);
            var[sizeof(var) - 1] = '\0';

            strncpy(func[x - 1], func[x], sizeof(func[x - 1]) - 1);
            func[x - 1][sizeof(func[x - 1]) - 1] = '\0';

            strncpy(func[x], var, sizeof(func[x]));
            func[x][sizeof(func[x]) - 1] = '\0';
            --x;
        }
    }
}

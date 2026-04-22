#include <stdio.h>
#include <stdlib.h>

struct ValueType
{
    int type;
    union
    {
        char  character;
        float number;
    } data;
};

int main()
{
    struct ValueType values[20];
    char  newline;
    int   i = -1;
    float average = 0.0;
    int   j, count = 0;

    // Collect input until type is not 0 or 1
    do
    {
        i++;
        printf("Enter an integer (0 for float, 1 for char):\n");
        scanf("%d", &values[i].type);
        scanf("%c", &newline);

        if (values[i].type == 1)
        {
            printf("Enter a character:\n");
            scanf("%c", &values[i].data.character);
            scanf("%c", &newline);
        }
        else if (values[i].type == 0)
        {
            printf("Enter a real number:\n");
            scanf("%f", &values[i].data.number);
        }
    }
    while (values[i].type == 0 || values[i].type == 1);

    // Calculate average of float values
    for (j = 0; j <= i; j++)
    {
        if (values[j].type == 0)
        {
            average += values[j].data.number;
            count++;
        }
    }

    average = average / count;
    printf("Average of real numbers: %.2f", average);

    return 0;
}

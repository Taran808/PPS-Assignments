#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks1;
    float marks2;
    float marks3;
    float total;
    float percentage;
};

int main()
{
    struct Student s[100];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter marks of 3 subjects: ");
        scanf("%f %f %f", &s[i].marks1, &s[i].marks2, &s[i].marks3);

        s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3;
        s[i].percentage = s[i].total / 3;
    }

    printf("\nRoll No\tName\tSubject 1\tSubject 2\tSubject 3\tTotal\tPercentage\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t%.2f\n",
               s[i].roll,
               s[i].name,
               s[i].marks1,
               s[i].marks2,
               s[i].marks3,
               s[i].total,
               s[i].percentage);
    }

    return 0;
}

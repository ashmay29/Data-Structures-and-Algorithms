// #include <stdio.h>
// #include <conio.h>
// #define MAX 10
// int queue[MAX];
// int front = -1, rear = -1;
// void insert(void);
// int delete_element(void);
// int peek(void);
// void display(void);
// int main()
// {
//     int option, val;
//     do
//     {
//         printf("\n\n ***** MAIN MENU *****");
//         printf("\n 1. Insert an element");
//         printf("\n 2. Delete an element");
//         printf("\n 3. Peek");
//         printf("\n 4. Display the queue");
//         printf("\n 5. EXIT");
//         printf("\n Enter your option : ");
//         scanf("%d", &option);
//         switch (option)
//         {
//         case 1:
//             insert();
//             break;
//         case 2:
//             val = delete_element();
//             if (val != -1)
//                 printf("\n The number deleted is : %d", val);
//             break;
//         case 3:
//             val = peek();
//             if (val != -1)
//                 printf("\n The first value in queue is : %d", val);
//             break;
//         case 4:
//             display();
//             break;
//         }
//     } while (option != 5);
//     getch();
//     return 0;
// }
// void insert()
// {
//     int num;
//     printf("\n Enter the number to be inserted in the queue : ");
//     scanf("%d", &num);
//     if (rear == MAX - 1)
//         printf("\n OVERFLOW");
//     else if (front == -1 && rear == -1)
//         front = rear = 0;
//     else
//         rear++;
//     queue[rear] = num;
// }
// int delete_element()
// {
//     int val;
//     if (front == -1 || front > rear)
//     {
//         printf("\n UNDERFLOW");
//         return -1;
//     }
//     else
//     {
//         val = queue[front];
//         front++;
//         if (front > rear)
//             front = rear = -1;
//         return val;
//     }
// }
// int peek()
// {
//     if (front == -1 || front > rear)
//     {
//         printf("\n QUEUE IS EMPTY");
//         return -1;
//     }
//     else
//     {
//         return queue[front];
//     }
// }
// void display()
// {
//     int i;
//     printf("\n");
//     if (front == -1 || front > rear)
//         printf("\n QUEUE IS EMPTY");
//     else
//     {
//         for (i = front; i <= rear; i++)
//             printf("\t %d", queue[i]);
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#define size 100
int h[size];
void display(int n)
{
    int i;
    printf("Elements in the hash table are:\n");
    for (i = 0; i < n; i++)
        printf("At index %d \t value = %d\n", i, h[i]);
}
void insert(int n)
{
    int key, index, i, flag = 0, hkey;
    printf("Enter a value to insert into the hash table: ");
    scanf("%d", &key);
    hkey = key % n;
    for (i = 0; i < n; i++)
    {
        index = (hkey + i) % n;
        if (h[index] == 0)
        {
            h[index] = key;
            break;
        }
    }
    if (i == n)
        printf("\nElement cannot be inserted\n");
}
void search(int n)
{
    int index, i, flag = 0, hkey, key;
    printf("\nEnter search element: ");
    scanf("%d", &key);
    hkey = key % n;
    for (i = 0; i < n; i++)
    {
        index = (hkey + i) % n;
        if (h[index] == key)
        {
            printf("Value %d is found at index %d\n", key, index);
            return;
        }
    }
    printf("\nValue %d is not found\n", key);
}
int main()
{
    int choice, key, n;
    printf("Aanshuvi Shah 60009220168\n");
    printf("Enter size of the hash table: ");
    scanf("%d", &n);
    while (1)
    {
        printf("MENU:\n");
        printf("1. Inserting Element in the Hashtable\n");
        printf("2. Display Hashtable\n");
        printf("3. Searching Element in the Hashtable\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(n);
            break;
        case 2:
            display(n);
            break;
        case 3:
            search(n);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Input\n");
            break;
        }
    }
}
char st[100];
int top = -1;
void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top !=-1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top ==-1)
            {
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st); // remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top !=-1) && (st[top] != '(') && (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while ((top !=-1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}
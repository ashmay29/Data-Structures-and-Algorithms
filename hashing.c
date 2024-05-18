//Hashing:
#include <stdio.h>
#include <stdlib.h>
#define size 100
int h[size];
void display(int n) {
 int i;
 printf("Elements in the hash table are:\n");
 for (i = 0; i < n; i++)
 printf("At index %d \t value = %d\n", i, h[i]);
}
void insert(int n) {
 int key, index, i, flag = 0, hkey;
 printf("Enter a value to insert into the hash table: ");
 scanf("%d", &key);
 hkey = key % n;
 for (i = 0; i < n; i++) {
 index = (hkey + i) % n;
 if (h[index] == 0) { 
 h[index] = key;
 break;
 }
 }
 if (i == n)
 printf("\nElement cannot be inserted\n");
}
void search(int n) {
 int index, i, flag = 0, hkey,key;
 printf("\nEnter search element: ");
 scanf("%d", &key);
 hkey = key % n;
 for (i = 0; i < n; i++) {
 index = (hkey + i) % n;
 if (h[index] == key) {
 printf("Value %d is found at index %d\n", key, index);
 return;
 }
 }
 printf("\nValue %d is not found\n", key);
}
int main() {
 int choice, key, n;
 printf("Aanshuvi Shah 60009220168\n");
 printf("Enter size of the hash table: ");
 scanf("%d", &n);
 while (1) {
 printf("MENU:\n");
 printf("1. Inserting Element in the Hashtable\n");
 printf("2. Display Hashtable\n");
 printf("3. Searching Element in the Hashtable\n");
 printf("4. Exit\n");
 printf("Please enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
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

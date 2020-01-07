#include <stdio.h>
#include <assert.h>
#include "HashTable.h"


int main(int argc, char *argv[])
{
    HashTable table;
    FILE *fp;
    int key, value, ret;
    printf("60\n");

    table = CreateEmptyHashTable(10, 7);
    assert(table->m == 10);
    assert(table->p == 7);
    // Enable the following function to check the table.
     PrintHashTable(table);
    printf("70\n");


	
    fp = fopen("insert.txt", "r");
    if (fp == NULL) return 0;
    while (!feof(fp)) {
        fscanf(fp, "%d %d\n", &key, &value);
        HashTableInsert(table, key, value);
    }
    fclose(fp);
    // Enable the following function to check the table.
     PrintHashTable(table);
    printf("80\n");

    fp = fopen("insert.txt", "r");
    if (fp == NULL) return 0;

    while (!feof(fp)) {
        fscanf(fp, "%d %d", &key, &value);
        assert(HashTableFind(table, key, &ret) == 1);		
        assert(ret == value);
    }
    fclose(fp);
    printf("90\n");

    DestroyHashTable(table);
    printf("100\n");
	
    return 0;
}

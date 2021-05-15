// COLLISION HANDLING # 1: OPEN CHAINING

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NIL INT_MIN
#define DEL INT_MAX
#define TABLE_SIZE 10

struct Hash_Table
{
    int data;
    struct Hash_Table *next;
};

struct Hash
{
    int hash_size;
    struct Hash_Table *array;
};

struct Hash *create_hash(void);
int hash_function(int key);
void insert(struct Hash *node, int key);
void delete_key(struct Hash *ptr, int key);
void print_hash(struct Hash *ptr);

int main(void)
{
    int number_of_elements, temp;
    struct Hash *hash_table = create_hash();
    printf("Enter the number of elements you want to hash: ");
    scanf("%d", &number_of_elements);
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("Enter the element value: ");
        scanf("%d", &temp);
        insert(hash_table, temp);
    }

    print_hash(hash_table);

    printf("Enter the key you want to delete: ");
    scanf("%d", &temp);

    delete_key(hash_table, temp);
    print_hash(hash_table);

    printf("Enter the key you want to insert: ");
    scanf("%d", &temp);

    insert(hash_table, temp);
    print_hash(hash_table);
    return 0;
}

struct Hash *create_hash(void)
{
    struct Hash *pointer = (struct Hash *)malloc(sizeof(struct Hash));
    pointer->hash_size = 0;
    pointer->array = (struct Hash_Table *)malloc(TABLE_SIZE * sizeof(struct Hash_Table));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        pointer->array[i].data = NIL;  // Initialzing every slot data as empty
        pointer->array[i].next = NULL; // Initialzing every pointer to next as NULL
    }
    return pointer;
}

int hash_function(int key)
{
    return key % 7;
}

void insert(struct Hash *node, int key)
{
    if (node->hash_size == TABLE_SIZE)
        return; // hash table is full

    int index = hash_function(key);
    struct Hash_Table *slot = &node->array[index];

    if (slot->data != NIL && slot->data != DEL)
    {
        while (slot->next)
        {
            if (slot->next->data == DEL)
            {
                slot->next->data = key;
                return;
            }
            slot = slot->next;
        }
        slot->next = (struct Hash_Table *)malloc(sizeof(struct Hash_Table));
        slot->next->data = key;
        slot->next->next = NULL;
    }
    else
    {
        slot->data = key;
    }
    node->hash_size++;
}

void delete_key(struct Hash *ptr, int key)
{
    struct Hash_Table *slot = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        slot = &ptr->array[i];
        if (slot->data != NIL)
        {
            do
            {
                if (slot->data == key)
                {
                    slot->data = DEL;
                    ptr->hash_size--;
                    return;
                }
                slot = slot->next;
            } while (slot);
        }
    }
}

void print_hash(struct Hash *ptr)
{
    struct Hash_Table *slot = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        slot = &ptr->array[i];
        if (slot->data != NIL)
        {
            do
            {
                if (slot->data != DEL)
                    printf("%d ", slot->data);
                slot = slot->next;
            } while (slot);
        }
        printf("\n");
    }
}
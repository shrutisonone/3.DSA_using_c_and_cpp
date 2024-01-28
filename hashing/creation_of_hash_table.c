#define LOAD_FACTOR 20

//a liked lsit of key 
struct ListNode
{
  int key;
  int data;
  struct ListNode *next;;
};

//hashtable liked list for storing blocks 
struct HastTableNode
{
    int bcount;
    struct ListNode *next;
};

//main Hash Table
struct HashTable
{
    int tsize;
    int count;
    struct HashTableNode **Table;
};

struct HashTable *createHashTable(int size)
{
    struct HashTable *h;
    h=(struct HashTable *)malloc(sizeof(struct HashTable));
    if(!h)
    {
        return NULL;
    }
    h->tsize=size/LOAD_FACTOR;
    h->count=0;
    h->Table = (struct HashTableNode **)malloc(sizeof(Struct HashTableNode *) *h->tsize);
    if(!h->Table)
    {
        printf("Memory Error\n");
        return NULL;
    }

    for(int i=0;i<h->tszize;i++)
    {
        h->Table[i]->next = NULL;
        h->Table[i]->bcount  =0;
    }
    return h;
}

int HashSearch(struct HashTable *h,int data)
{
    struct ListNode *temp;
    temp = h->Table[Hash(data,h->tsize)]->next;
    while(temp)
    {
        if(temp->data == data)
        return 1;
        temp = temp -> next;
    }
    return 0;
}

int Hashinsert(struct HashTable *h,int data)
{
    int index;
    struct ListNode *temp,*newNode;
    if(HashSearch(h,data))
       return 0;
    index = Hash(data,h->size);
    temp = h ->Table[index]->next;
    newNode = (struct ListNode *)malloc(sizeof(structListNode));
    if(!newNode)
    {
        printf("Out of Space\n");
        return -1;
    }

    newNode -> key = index;
    newNode -> data = data;
    newNode -> next = h -> Table[index]->next;

    h->Table[index]->next = newNode;
    h->Table[index]->bcount++;
    h->count++;

    if(h->count / h->size > LOAD_FACTOR)
     {
        return 1;
     }
}


int HashDelete(struct HashTable *h,int data)
{
    int index;
    struct Listnode *temp,*prev;
    index = Hash(data,h->tsize);

    for(temp = h->Table[index]->next,prev=NULL: temp: prev=temp,temp=temp->next)
    {
        if(temp -> data == data)
        {
            if(prev != NULL)
            {
                prev -> next = temp -> next;
            }
            free temp;
            h->Table[index]->bcount;
            h->count--;
            return 1;
        }
    }
    return 0;
}


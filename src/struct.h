#define MAX_STRING 100

struct Barang {
    int id;
    int category;
    int status;
    char name[MAX_STRING];
    char location[MAX_STRING];
    char pic[MAX_STRING];
};

struct List {
    struct Barang* barang;
    struct List* next;
    struct List* prev;
};
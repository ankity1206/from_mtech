typedef struct {
    int time;
    int patient;
    int facility;
    int duration;
    int step; // which service index
} Event;

typedef struct {
    Event *arr;
    int size;
} Heap;

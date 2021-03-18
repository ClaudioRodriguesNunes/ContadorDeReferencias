#include"contref.h"

int main(){
    int *v = malloc2(sizeof(int));
    *v = 10;
    int *w = malloc2(sizeof(int));
    dump();
    *w = 20;
    v = atrib3(v, w);
    //atrib2(&v, w);
    dump();
    char *c = malloc2(sizeof(char));
    *c = 'Z';
    dump();
    w = atrib3(w, NULL);
    //atrib2(&w, NULL);
    dump();
    return 0;
}



#include "grader.h"
#include "memory.h"
#include <bits/stdc++.h>
using namespace std;

void play() {
    int id1[25];
    int id2[25];
    memset(id1, 0, sizeof(id1));
    memset(id2, 0, sizeof(id2));

    for(int i=1; i<=50; i++) {
        char x = faceup(i);
        if(id1[x-'A'] == 0) id1[x-'A'] = i;
        else id2[x-'A'] = i;
    }

    int candies = 0;
    for(int i=0; i<25; i++) {
        char a = faceup(id1[i]);
        char b = faceup(id2[i]);
        candies += (a == b);
        if(candies == 25) return ;
    }
    
    return;
}
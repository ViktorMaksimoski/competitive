#include "grader.h"
#include "cluedo.h"
#include <set>
 
void Solve(){
   int r = 4;
   
   std::set<int> mur, place, weapons;
 
    for(int i=1; i<=6; i++)
    {
        for(int j=1; j<=10; j++)
        {
            for(int k=1; k<=6; k++)
            {
                if(mur.find(i) == mur.end() && place.find(j) == place.end() && weapons.find(k) == weapons.end())
                {
                    r = Theory(i, j, k);
                    
                    if(r == 0) return ;
                    else if(r == 1) mur.insert(i);
                    else if(r == 2) place.insert(j);
                    else if(r == 3) weapons.insert(k);
                }
            }
        }
    }
}
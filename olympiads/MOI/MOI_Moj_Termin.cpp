#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm>  
using namespace std;  
   
int main()  
{  
    int L;  
    cin >> L;  
   
    vector<string> O;  
    O.resize(L+1);  
   
    for (int i=1; i<=L; i++) {  
        cin >> O[i];  
    }  
   
    int options[L+1];  
    options[0] = 1;  
   
    for (int i=1; i<=L; i++) {  
        options[i] = 0;  
   
        for (int sz=1; sz<=i; sz++) {  
   
            //dali mozhe tuka da zavrshuva grupa od "sz" lica?  
            //mozhe, ako poslednite "sz" elementi se ili ednakvi na "N" ili na "sz"  
   
            bool good = true;  
            int from = i-sz+1, to = i; //poslednite "sz" elementi se od "from" do "to"  
            for (int j=from; j<=to; j++) {  
                if (O[j] != "N" && stoi(O[j]) != sz) {  
                    good = false;      //broj razlichen od "sz"  
                    break;  
                }  
            }  
   
            if (good) {  
                options[i] = options[i] + options[i - sz];  
   
                if (options[i] > 1) {    //ne ni treba tochniot rezultat  
                    options[i] = 2;      //samo ne interesira dali ima 1 ili povekje (2+) opcii  
                                         //(za sluchajno da ne ni se pojavi overflow, iako nema vo test primerite)  
                }  
            }  
        }  
    }  
   
    if (options[L] == 1) {  
        cout << "DA" << endl;  
    } else {  
        cout << "NE" << endl;  
    }  
    return 0;  
}  
// -------------------------------------------------------
// (c) 2017 Jens Kallup  e-Mail: kallup.jens@web.de
// non-profit
//
// Erstellt mit: Linux GNU-C Compiler 6.3.0 -std=c++14
// Terminal:     gcc -o test test.c
// Zweck:        4 echte, unter 8 Muenzen finden.
//
// X-Mas:        2017, hoho, and happy new year :-)
// -------------------------------------------------------
#include <stdio.h>

#define muenzen 8

/*
** Fragesteller: 1 - echt, 0 - falsch
*/
int muenz_filter[muenzen] = { 1, 0, 0, 1, 1, 1, 0, 0 };

/*
** Muenz-Maske(n) - muessten eigentlich 32 statt 26 sein !
** Bitte noch abgleichen...
**
** Dieser Array dient der Anschauung, er kann natuerlich
** auch vom Programm selbst aufgestellt werden...
** Wird dies gewuenscht, so lasst es mich wissen, da ich
** denke, es schwierig ist per Hand Korrekturen zu machen.
*/
int mecht_array[27][muenzen] =
{
 { 1, 0, 0, 1, 1, 1, 0, 0 },
 { 0, 0, 0, 0, 1, 1, 1, 1 }, // 15  => 5,6,7,8
 { 0, 0, 0, 1, 0, 1, 1, 1 }, // 23  => 4,6,7,8
 { 0, 0, 0, 1, 1, 0, 1, 1 }, // 27  => 4,5,7,8
 { 0, 0, 0, 1, 1, 1, 0, 1 }, // 29  => 4,5,6,8
 { 0, 0, 0, 1, 1, 1, 1, 0 }, // 30  => 4,5,6,7
 { 0, 0, 1, 0, 1, 1, 0, 1 }, // 45  => 4,5,6,7
 { 0, 0, 1, 0, 1, 1, 1, 0 }, // 46  => 4,5,6,7
 { 0, 0, 1, 1, 1, 1, 0, 0 }, // 60  => 4,5,6,7
 { 0, 0, 1, 1, 1, 0, 0, 1 }, // 61  => 4,5,6,7
 { 0, 0, 1, 1, 1, 0, 1, 0 }, // 62  => 4,5,6,7
 { 0, 1, 0, 0, 0, 1, 1, 1 }, // 71  => 4,5,6,7
 { 0, 1, 0, 0, 1, 1, 1, 0 }, // 78  => 4,5,6,7
 { 0, 1, 0, 1, 1, 1, 0, 0 }, // 92  => 4,5,6,7
 { 0, 1, 1, 0, 0, 0, 1, 1 }, // 99  => 4,5,6,7
 { 0, 1, 1, 0, 0, 1, 1, 0 }, // 102 => 4,5,6,7
 { 0, 1, 1, 0, 1, 0, 0, 1 }, // 105 => 4,5,6,7
 { 0, 1, 1, 0, 1, 0, 1, 0 }, // 106 => 4,5,6,7
 { 0, 1, 1, 1, 1, 0, 0, 0 }, // 120 => 4,5,6,7
 { 0, 1, 1, 1, 0, 0, 0, 1 }, // 113 => 4,5,6,7
 { 0, 1, 1, 1, 0, 0, 1, 0 }, // 114 => 4,5,6,7
 { 0, 1, 1, 1, 0, 1, 0, 0 }, // 116 => 4,5,6,7
 { 1, 1, 1, 1, 0, 0, 0, 0 }, // 240 => 4,5,6,7
 { 1, 1, 1, 0, 0, 0, 0, 1 }, // 225 => 4,5,6,7
 { 1, 1, 1, 0, 0, 0, 1, 0 }, // 226 => 4,5,6,7
 { 1, 1, 1, 0, 0, 1, 0, 0 }, // 228 => 4,5,6,7
 { 1, 1, 1, 0, 1, 0, 0, 0 }  // 232 => 4,5,6,7
};

// --------------------
// Hauptprogramm in C 
// --------------------
int main()
{
    int i = 1;  // filter index
    int m = 1;  // state
    while ((i)<=26) {
        while ((m)<8) {
            if ((muenz_filter[m-1] == 1)
            && (mecht_array[i-1][m-1] == 1))
            printf("Muenze: %d  | echt\n", m);
            ++m;
        }   ++i;
    }
    return 0;
}


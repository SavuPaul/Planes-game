#include "./utils.h"

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    int index = 0, ok = 0, deplasare_completa = 0;
    char directie = '0', tip = '0';
    unsigned short x1 = 0, y1 = 0;
    const int next_plane = 8;

    for (int t = 0; t < nr_avioane; t++) {
        x1 = *((unsigned short*)(info + index));  // x-ul avionului curent
        index = index + 2;
        y1 = *((unsigned short*)(info + index));  // y-ul avionului curent
        index = index + 2;
        directie = *((char*)(info + index));  // directia avionului curent
        index = index + 1;
        tip = *((char *)(info + index));  // tipul avionului curent
        index = index + next_plane;
        ok = 0;

        switch (tip) {
            case '1':
                switch (directie) {
                    case 'N':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if (x[i] >= (x1 + 3) || (y[i] > y1 + 2 || y[i] < y1 - 2)) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'S':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if ((y[i] > (y1 + 2) || y[i] < (y1 - 2)) || x[i] <= x1 - 3) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'E':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if ((x[i] < (x1 - 2) || x[i] > (x1 + 2)) || y[i] <= y1 - 3) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'W':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if ((x[i] < (x1 - 2) || x[i] > (x1 + 2)) || y[i] >= y1 + 3) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                }
                break;
            case '2':
                switch (directie) {
                    case 'N':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if (x[i] >= x1 + 4 || ((y[i] > y1 + 3) || (y[i] < y1 - 3))) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'S':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if (x[i] <= (x1 - 4) || ((y[i] < y1 - 3) || (y[i] > (y1 + 3)))) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'E':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if (y[i] <= (y1 - 4) || (x[i] < x1 - 3 || x[i] > x1 + 3)) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                    case 'W':
                        ok = 0;
                        for (int i = 0 ; i < nr_obstacole; i++) {
                            if (y[i] >= (y1 + 4) || (x[i] < x1 - 3 || x[i] > x1 + 3)) {
                                ok++;
                            }
                        }
                        if (ok == nr_obstacole) {
                            deplasare_completa++;
                        }
                        ok = 0;
                        break;
                }
                break;
        }
    }
    printf("%d\n", deplasare_completa);
}
// trebuie sa aflu directia avionului, tipul avionului
/* pentru fiecare avion verific daca pe anvergura sa, in directia in care
    se deplaseaza, exista obstacole */

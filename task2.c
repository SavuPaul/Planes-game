#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    int i = 0, j = 0, t = 0, index = 0;
    char directie = '0', tip = '0';
    unsigned short x = 0, y = 0;
    const int next_plane = 8;

    // completarea matricei conform coordonatelor avioanelor
    for (int t = 0; t < nr_avioane; t++) {  // pentru fiecare avion in parte
        x = *((unsigned short*)(info + index));  // x-ul avionului curent
        index = index + 2;
        y = *((unsigned short*)(info + index));  // y-ul avionului curent
        index = index + 2;
        directie = *((char*)(info + index));  // directia avionului curent
        index = index + 1;
        tip = *((char *)(info + index));  // tipul avionului curent
        index = index + next_plane;

        mat[x][y] = '*';

        switch (tip) {
            case '1':
                switch (directie) {
                    case 'N':
                        mat[x+1][y-2] = mat[x+1][y-1] = mat[x+1][y] =
                        mat[x+1][y+1] = mat[x+1][y+2] = '*';  // completarea randului 2
                        mat[x+2][y] = '*';  // completarea randului 3
                        mat[x+3][y-1] = mat[x+3][y] = mat[x+3][y+1] = '*';  // completarea randului 4
                        break;

                    case 'S':
                        mat[x-1][y-2] = mat[x-1][y-1] = mat[x-1][y] =
                        mat[x-1][y+1] = mat[x-1][y+2] = '*';  // completarea randului 2
                        mat[x-2][y] = '*';  // completarea randului 3
                        mat[x-3][y-1] = mat[x-3][y] = mat[x-3][y+1] = '*';  // completarea randului 4
                        break;

                    case 'E':
                        mat[x-2][y-1] = mat[x-1][y-1] = mat[x][y-1] =
                        mat[x+1][y-1] = mat[x+2][y-1] = '*';  // completarea randului 2
                        mat[x][y-2] = '*';  // completarea randului 3
                        mat[x-1][y-3] = mat[x][y-3] = mat[x+1][y-3] = '*';  // completarea randului 4
                        break;

                    case 'W':
                        mat[x-2][y+1] = mat[x-1][y+1] = mat[x][y+1] =
                        mat[x+1][y+1] = mat[x+2][y+1] = '*';  // completarea randului 2
                        mat[x][y+2] = '*';  // completarea randului 3
                        mat[x-1][y+3] = mat[x][y+3] = mat[x+1][y+3] = '*';  // completarea randului 4
                        break;
                }
                break;

            case '2':
                switch (directie) {
                    case 'N':
                        mat[x+1][y-1] = mat[x+1][y] = mat[x+1][y+1] = '*';  // completarea randului 2
                        mat[x+2][y-3] = mat[x+2][y-2] = mat[x+2][y-1] = mat[x+2][y] =
                        mat[x+2][y+1] = mat[x+2][y+2] = mat[x+2][y+3] = '*';  // completarea randului 3
                        mat[x+3][y] = '*';  // completarea randului 4
                        mat[x+4][y-2] = mat[x+4][y-1] = mat[x+4][y] =
                        mat[x+4][y+1] = mat[x+4][y+2] = '*';  // completarea randului 5
                        break;

                    case 'S':
                        mat[x-1][y-1] = mat[x-1][y] = mat[x-1][y+1] = '*';  // completarea randului 2
                        mat[x-2][y-3] = mat[x-2][y-2] = mat[x-2][y-1] = mat[x-2][y] =
                        mat[x-2][y+1] = mat[x-2][y+2] = mat[x-2][y+3] = '*';  // completarea randului 3
                        mat[x-3][y] = '*';  // completarea randului 4
                        mat[x-4][y-2] = mat[x-4][y-1] = mat[x-4][y] =
                        mat[x-4][y+1] = mat[x-4][y+2] = '*';  // completarea randului 5
                        break;

                    case 'E':
                        mat[x-1][y-1] = mat[x][y-1] = mat[x+1][y-1] = '*';  // completarea randului 2
                        mat[x-3][y-2] = mat[x-2][y-2] = mat[x-1][y-2] = mat[x][y-2] =
                        mat[x+1][y-2] = mat[x+2][y-2] = mat[x+3][y-2] = '*';  // completarea randului 3
                        mat[x][y-3] = '*';  // completarea randului 4
                        mat[x-2][y-4] = mat[x-1][y-4] = mat[x][y-4] =
                        mat[x+1][y-4] = mat[x+2][y-4] = '*';  // completarea randului 5
                        break;

                    case 'W':
                        mat[x-1][y+1] = mat[x][y+1] = mat[x+1][y+1] = '*';  // completarea randului 2
                        mat[x-3][y+2] = mat[x-2][y+2] = mat[x-1][y+2] = mat[x][y+2] =
                        mat[x+1][y+2] = mat[x+2][y+2] = mat[x+3][y+2] = '*';  // completarea randului 3
                        mat[x][y+3] = '*';  // completarea randului 4
                        mat[x-2][y+4] = mat[x-1][y+4] = mat[x][y+4] =
                        mat[x+1][y+4] = mat[x+2][y+4] = '*';  // completarea randului 5
                        break;
                }
                break;
        }
    }

    // afisarea matricei
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

#include "./utils.h"
/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/

// sortare crescatoare dupa viteza
int speed_asc(const void *a, const void *b) {
    char cod1[3] = "", cod2[3] = "", c1 = 'a', c2 = 'a';

    // variabilele constante sunt folosite pentru a determina pozitia caracterului / numarului necesar din vector
    const int firstchar_code = 6, plane_type = 5, plane_speed = 9;
    char tip1 = 'a', tip2 = 'a';
    int ok = 1;
    for (int i = 0; i < 3; i++) {
        c1 = *((char*)(a + i + firstchar_code));
        c2 = *((char*)(b + i + firstchar_code));
        if (c1 != c2) {
            ok = 0;
            break;
        }
    }
    unsigned int viteza1 = *((unsigned int*)(a + plane_speed));
    unsigned int viteza2 = *((unsigned int*)(b + plane_speed));
    tip1 = *((char*)(a + plane_type));
    tip2 = *((char*)(b + plane_type));
    if (viteza1 > viteza2 && ok == 1 && tip1 == tip2) {
        return 1;
    }
    if (viteza1 < viteza2 && ok == 1 && tip1 == tip2) {
        return -1;
    }
    if (viteza1 == viteza2 && ok == 1 && tip1 == tip2) {
        return 0;
    }
}

// sortare descrescatoare cod aeroport
int code_desc(const void *a, const void *b) {
    char cod1[3] = "", cod2[3] = "", tip1 = 'a', tip2 = 'a', c1 = 'a', c2 = 'a';
    int i = 0;
    // variabilele constante sunt folosite pentru a determina pozitia caracterului / numarului necesar din vector
    const int plane_type = 5, firstchar_code = 6;

    tip1 = *((char*)(a + plane_type));
    tip2 = *((char*)(b + plane_type));

    c1 = *((char*)(a + firstchar_code));
    c2 = *((char*)(b + firstchar_code));
    if (c1 > c2 && tip1 == tip2) {
        return 1;
    }
    if (c1 < c2 && tip1 == tip2) {
        return -1;
    }
    if (c1 == c2 && tip1 == tip2) {
        c1 = *((char*)(a + firstchar_code + 1));
        c2 = *((char*)(b + firstchar_code + 1));
        if (c1 > c2 && tip1 == tip2) {
          return 1;
        }
        if (c1 < c2 && tip1 == tip2) {
            return -1;
        }
        if (c1 == c2 && tip1 == tip2) {
            c1 = *((char*)(a + firstchar_code + 2));
            c2 = *((char*)(b + firstchar_code + 2));
            if (c1 > c2 && tip1 == tip2) {
                return 1;
            }
            if (c1 < c2 && tip1 == tip2) {
                return -1;
            }
            if (c1 == c2 && tip1 == tip2) {
                return 0;
            }
        }
    }
}

// sortare crescatoare dupa tip
int tip_asc(const void *a, const void *b) {
    char tip1 = 'a', tip2 = 'a';
    // variabilele constante sunt folosite pentru a determina pozitia caracterului / numarului necesar din vector
    const int plane_type = 5;
    tip1 = *((char*)(a + plane_type));
    tip2 = *((char*)(b + plane_type));
    if (tip1 > tip2) {
        return 1;;
    }
    if (tip1 < tip2) {
        return -1;
    }
    if (tip1 == tip2) {
        return 0;
    }
}

void SolveTask3(void *info, int nr_avioane) {
    const int plane_size = 13;

    qsort(info, nr_avioane, plane_size, tip_asc);
    qsort(info, nr_avioane, plane_size, code_desc);
    qsort(info, nr_avioane, plane_size, speed_asc);

    // afisare vector
    int i = 0;
    const int dim_info = 13;
    for (int j = 0; j < nr_avioane; j++) {
        printf("(%hu, %hu)\n",
                 *((unsigned short*)(info + i)),
                 *((unsigned short*)(info + i + sizeof(unsigned short))));
        i = i + 4;
        printf("%c\n", *((char*)(info + i)));
        i = i + 1;
        for (int t = 0; t <= 3; t++) {
            printf("%c", *((char*)(info + i)));
            i = i + 1;
        }
        printf("\n");
        printf("%u\n", *((unsigned int*)(info + i)));
        i = i + 4;
        printf("\n");
    }
}

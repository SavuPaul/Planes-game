#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    int i = 0;
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

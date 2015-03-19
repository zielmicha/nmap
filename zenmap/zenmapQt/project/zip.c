#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void writefile(const char* path, int size, const char* data) {
    printf("writing %s\n", path);
    FILE* f = fopen(path, "w");
    if(!f) {
        perror("fopen");
        abort();
    }
    size_t w = fwrite(data, size, 1, f);
    if(w != 1) {
        perror("fwrite");
        abort();
    }
    fclose(f);
}

void dounzip() {
#include "zip.h"
}

#ifdef ZIP_C_MAIN
int main() {
    dounzip();
}
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

int myInflate(const void *src, int srcLen, void *dst, int dstLen) {
    z_stream strm  = {0};
    strm.total_in  = strm.avail_in  = srcLen;
    strm.total_out = strm.avail_out = dstLen;
    strm.next_in   = (Bytef *) src;
    strm.next_out  = (Bytef *) dst;

    strm.zalloc = Z_NULL;
    strm.zfree  = Z_NULL;
    strm.opaque = Z_NULL;

    int err = -1;
    int ret = -1;

    err = inflateInit2(&strm, (15 + 32)); //15 window bits, and the +32 tells zlib to to detect if using gzip or zlib
    if (err == Z_OK) {
        err = inflate(&strm, Z_FINISH);
        if (err == Z_STREAM_END) {
            ret = strm.total_out;
        }
        else {
             inflateEnd(&strm);
             return err;
        }
    }
    else {
        inflateEnd(&strm);
        return err;
    }

    inflateEnd(&strm);
    return ret;
}

void writefile(const char* path, int uncompressed,
               int size,
               const char* compressedData) {
    printf("writing %s\n", path);
    char* data = malloc(uncompressed);
    int ret =
      myInflate(compressedData, size, data, uncompressed);
    if(ret < 0) {
        printf("inflate failed\n");
        abort();
    }
    FILE* f = fopen(path, "w");
    if(!f) {
        perror("fopen");
        abort();
    }
    size_t w = fwrite(data, uncompressed, 1, f);
    if(w != 1) {
        perror("fwrite");
        abort();
    }
    fclose(f);
    free(data);
}

void dounzip() {
#include "zip.h"
}

#ifdef ZIP_C_MAIN
int main() {
    dounzip();
}
#endif

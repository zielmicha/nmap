#!/bin/bash
A=build-python
mkdir -p $A/lib
mkdir $A/lib/python2.7
echo > $A/lib/python2.7/site.py

echo 'array = str' > $A/lib/python2.7/array.py
STDMODULES="shutil stat os posixpath traceback linecache
types posixpath genericpath warnings fnmatch collections
functools threading httplib urllib string re UserDict _abcoll
abc copy_reg sre_compile sre_constants sre_parse keyword
heapq bisect random __future__ glob socket StringIO urlparse
mimetools tempfile rfc822 gzip struct io subprocess pickle
atexit encodings/__init__ encodings/ascii encodings/utf_8
encodings/aliases encodings/hex_codec codecs SocketServer"
mkdir $A/lib/python2.7/encodings
for mod in $STDMODULES; do
    cp python4android/Python-2.7/Lib/$mod.py $A/lib/python2.7/$mod.py || exit 1
done

python makezip.py

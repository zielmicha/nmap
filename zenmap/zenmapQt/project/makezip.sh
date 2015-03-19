#!/bin/bash
A=build-python
rm -r "$A"
mkdir -p $A/lib
mkdir $A/lib/python2.7
echo > $A/lib/python2.7/site.py
echo > $A/lib/python2.7/doctest.py
echo 'def getpreferredencoding(): return "utf8"
def getdefaultlocale(): raise ValueError
class Error(exception): pass
def setlocale(*args, **kwargs): raise Error()' > $A/lib/python2.7/locale.py
echo 'class TestCase: pass' > $A/lib/python2.7/unittest.py
echo 'from StringIO import *' > $A/lib/python2.7/cStringIO.py

cp -rv ../../zenmapCore $A/lib/python2.7/zenmapCore

echo 'array = str' > $A/lib/python2.7/array.py
STDMODULES="shutil stat os posixpath traceback linecache
types posixpath genericpath warnings fnmatch collections
functools threading httplib urllib string re UserDict _abcoll
abc copy_reg sre_compile sre_constants sre_parse keyword
heapq bisect random __future__ glob socket StringIO urlparse
mimetools tempfile rfc822 gzip struct io subprocess pickle
atexit encodings/__init__ encodings/ascii encodings/utf_8
encodings/aliases encodings/hex_codec codecs SocketServer
locale copy weakref _weakrefset xml/__init__
xml/sax/_exceptions xml/sax/expatreader
xml/sax/handler xml/sax/__init__ xml/sax/saxutils
xml/sax/xmlreader
logging/__init__
optparse textwrap"
mkdir $A/lib/python2.7/encodings
mkdir -p $A/lib/python2.7/xml/sax
mkdir $A/lib/python2.7/logging
for mod in $STDMODULES; do
    cp python4android/Python-2.7/Lib/$mod.py $A/lib/python2.7/$mod.py || exit 1
done

python makezip.py > zip.h

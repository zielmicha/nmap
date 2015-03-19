import subprocess
import os
import zlib

base = 'build-python/'
files = subprocess.check_output(['find'], cwd=base).splitlines()
files = [ (base + file, file) for file in files ]
files += [
    ('../../../nmap', 'nmap'),
]

for src, file in files:
    if os.path.isdir(src):
        print 'mkdir("%s", 0700);' % file
    else:
        data = open(src, 'r').read()
        datacompress = zlib.compress(data)
        dataenc = ''.join([ '\\x%02X' % ord(ch) for ch in datacompress ])
        print 'writefile("%s", %d, %d, "%s");' % (file, len(data), len(datacompress), dataenc)

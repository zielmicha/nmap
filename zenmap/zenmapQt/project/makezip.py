import subprocess
import os

base = 'build-python/'
files = subprocess.check_output(['find'], cwd=base).splitlines()

for file in files:
    if os.path.isdir(base + file):
        print 'mkdir("%s", 0700);' % file
    else:
        data = open(base + file, 'r').read()
        dataenc = ''.join([ '\\x%02X' % ord(ch) for ch in data ])
        print 'writefile("%s", %d, "%s");' % (file, len(data), dataenc)

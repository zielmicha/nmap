
import encodings.ascii
import encodings.utf_8
import encodings.string_escape

print 'main: init'

import scanner
scanner.android = True

import os
os.chmod('nmap', 0o700)
os.environ['PATH'] += ':' + os.getcwd()

import subprocess
import traceback
from zenmapCore import NmapParser

android = False

def scan(ip):
    try:
        return scan_real(ip)
    except:
        traceback.print_exc()
        return 'Error: ' + traceback.format_exc()

def scan_real(ip):
    ret = subprocess.check_output(['nmap',
                                   '--dns-servers', '8.8.8.8',
                                   '-oX', 'nmap.xml', '127.0.0.1'])
    sax = NmapParser.NmapParserSAX()
    parser = NmapParser.make_parser()
    parser.setContentHandler(sax)
    parser.setEntityResolver(NmapParser.OverrideEntityResolver())
    sax.set_parser(parser)
    sax.parse_file('nmap.xml')
    return str(ret + '\nParsed data (in raw form):\n' + repr((
        sax.nmap
    )))

if __name__ == '__main__':
    print scan('')

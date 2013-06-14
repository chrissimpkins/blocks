
"""
compress.py

Created by Christopher Simpkins on 2013-06-12.
Copyright (c) 2013 Christopher Simpkins. MIT License.
"""
import gzip

# write a file with gzip compression
### Arguments : filepath = out file path | string = text string to compress and write to file
### Returns : int flag (0=success, 1=failure)
def gzip_write(filepath, string):
    try:
        f = gzip.open(filepath, 'wb')
        f.write(string)
        f.close()
        return 0
    except IOError as e:
        print "I/O error({0}): {1}".format(e.errno, e.strerror)
        return 1
    except:
        print "Compression write error. Unable to complete the gzip compression and file write"
        return 1

# read a gzip compressed file and return text string
### Arguments : filepath = in file path
### Returns : python string
def gzip_read(filepath):
    try:
        f = gzip.open(filepath)
        file_string = f.read()
        f.close()
        return file_string
    except IOError as e:
        print "I/O error({0}): {1}".format(e.errno, e.strerror)
        return 1
    except:
        print "Compression read error. Unable to read the gzip compressed file"
        return 1

def main():
    pass

if __name__ == '__main__':
    main()

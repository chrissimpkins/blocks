"""
network.py

Created by Christopher Simpkins on 2013-06-12.
Copyright (c) 2013 Christopher Simpkins. MIT License.
"""

import urllib2

# print html to std out
    # returns int
def print_html(the_url):
    request = urllib2.Request(the_url)
    data = urllib2.urlopen(request).read()
    print(data)
    return 0

# return html as a string
    # returns string
def get_html(the_url):
    request = urllib2.Request(the_url)
    data = urllib2.urlopen(request).read()
    return data

def main():
    pass

if __name__ == '__main__':
    main()
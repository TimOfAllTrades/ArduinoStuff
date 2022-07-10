import urllib.request
contents = urllib.request.urlopen("http://192.168.50.142/?789789789789789789").read()
print(contents)
#this seems to be the only way that works since any attempts to access javascript code on the arduino results in the SOP error.

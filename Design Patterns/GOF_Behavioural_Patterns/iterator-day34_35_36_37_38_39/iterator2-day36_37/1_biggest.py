# find the biggest file
# wrong program; does not work
import os
all = os.listdir()
print(all)
files = filter(os.path.isfile, all)
#print(list(files))
sizes = map(os.path.getsize, files)
#print(list(sizes))
pairs = zip(files, sizes)
print(list(pairs))


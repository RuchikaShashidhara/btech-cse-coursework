import os
#names = list(filter(lambda name : os.path.getsize(name) == 0 ,filter(os.path.isfile, os.listdir())))
#print(names)
list(map(os.unlink, filter(lambda name : os.path.getsize(name) == 0 ,filter(os.path.isfile, os.listdir()))))
print("end")
# lazy nature of iterables (some) in Python

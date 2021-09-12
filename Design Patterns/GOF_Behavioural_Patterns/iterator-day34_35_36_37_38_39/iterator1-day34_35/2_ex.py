# iterable
#	all collections are iterable
#	some iterables are eager; some are lazy
#	some can be traversed only once


a = [11, 22, 33, 44]
"""
it = iter(a)
print(it)
print(next(it))
print(next(it))
print(next(it))
print(next(it))
#print(next(it)) # StopIteration
"""
"""
it = iter(a) # a.__iter__()
while True:
	try:
		print(next(it)) # it.__next__()
	except:
		break
"""
"""
# exactly same as the while loop above
for e in a :
	print(e)
	
# ------------------
print(3 + 4)
print(3 .__add__(4))
print(int.__add__(3, 4))

# ------------------
"""
# what is the loop variable?
# copy or reference
a = [11, 22, 33, 44]
for e in a :
	e += 100
	print(e)
print(a) # not changed

a = [[11], [22], [33], [44]]
for e in a :
	e = [100]
	print(e)
print(a) # not changed

a = [[11], [22], [33], [44]]
for e in a :
	e = e + [100]
	print(e)
print(a)  # not changed

a = [[11], [22], [33], [44]]
for e in a :
	e += [100]
	print(e)
print(a)  # changes

#-----------------------------

"""
# infinite loop
a = [11, 22, 33, 44]
for e in a :
	print(e)
	a.append(e+11)
"""	
"""
a = [11, 22, 33, 44]
for e in a :
	print(e)
	a.pop()
"""
"""
a = set([11, 22, 33, 44])	# uses hashing, hence set, dictionary, etc. cannot be modified, as after removing elements in hash, the hashing functionality could reorder multiple times
for e in a :
	print(e)
	a.remove(e) # runtime error
"""





















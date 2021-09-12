# iterable:
#	1. __iter__ in the collection class
#		return an object => iterable object
#	2. __next__ in the iterable object
#		next element each time based on implementation
#		throws an exception StopIteration at end
class MyIterator:
	def __init__(self, c) :
		self.c = c
		self.i = 0
	def __next__(self):
		self.i += 1
		if self.i > len(self.c.c) :
			raise StopIteration
		return self.c.c[self.i - 1]	
class MyCollection:
	def __init__(self, *arg):
		self.c = list(arg)
	def __iter__(self) :
		return MyIterator(self)

		
	
a = MyCollection(2, 4, 6, 8, 10)
it = iter(a)
try:
	print(next(it))
	print(next(it))
	print(next(it))
	print(next(it))
	print(next(it))
	print(next(it))
except:
	print("over")
for e in a :
	print(e)
print(list(map(lambda x : x * x, a)))	
for e in a :
	print(e)	
	
it1 = iter(a)
it2 = iter(a)
print(next(it1)) # 2
print(next(it2)) # 2
it3 = iter(a)
print(next(it2)) # 4

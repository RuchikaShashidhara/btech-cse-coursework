# types : dynamic; based on assignment
#	value type
#	reference type
# parameter passing is by value only
# value type : arg can never change
# reference type :
#	change the reference : nothing happens to the arg (assignment =)
#	change thro the referencee : arg also changes (append, del, elements of the ref data structure)

# a value has a location; variable is a label for the location
# num of variables may share the same location
# life time of a value depends on the reference count
"""
a = 10
b = 10
c = 5 + 5


def f1(a) :
	a = 20
x = 10
f1(x)
print(x) # 10

def f2(a) :
	a = [20]
x = [10]
f2(x)
print(x) # [10]

def f3(a) :
	a.append(20)
	
x = [10]
f3(x)
print(x) # [10, 20]

"""
"""
# does not work
def swap(a, b) :
	t = a
	a = b
	b = t
	
x = 10; y = 20; swap(x, y); print(x, y)
x = [11, 22]; y = [33, 44]; swap(x, y); print(x, y)

"""
def foo(a, b) :
	a = a + b	# create a new list for a, in the same activation record, remains here only
x = [11, 22]; y = [33, 44]
foo(x, y)
print(x, y)	# [11,22] [33,44]
# val of a has not changed

def bar(a, b) :
	a += b		# appends ele of b to the same list of a, will persist in the global activation record
x = [11, 22]; y = [33, 44]
bar(x, y)
print(x, y)	# [11,22,33,44] [33,44]
# val of a has changed


a = 5; b = 8
(a, b) = (b, a + b)
print(a, b)








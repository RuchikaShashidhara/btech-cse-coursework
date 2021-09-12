"""
# version 1
# basic
def foo() :
	print("hello world")
foo()
"""

"""
# version 2
# function defined inside a function
def foo() :
	def what() :
		print("hello world")
	what()
foo()
"""

"""
# version 3
# Closure - what will still persist in the activation records
def foo() :
	def what() :
		print("hello world")
	return what
foo()()
"""

"""
# version 4
# same as version 3, but what() is cached in p()
def foo() :
	def what() :
		print("hello world")
	return what
p = foo()
p()
"""

"""
# version 5
# calls a function defined outside the outer function
def foo(test) :
	def what() :
		test()
	what()
	
def myfn() :
	print("hello world")
foo(myfn)
"""

"""
# version 6
# same as version 5, but final what() call is cached in p()
def foo(test) :
	def what() :
		test()
	return what
	
def myfn() :
	print("hello world")
	
bar = foo(myfn)
bar()
"""

"""
# version 7
# same as version 6, but before & then hello world is printed
def foo(test) :
	def what() :
		print("before")
		test()
	return what
	
def myfn() :
	print("hello world")
	
bar = foo(myfn)
bar()
"""

# engineered decorator
# version 8
def foo(test) :
	def what() :
		print("before")
		test()
	return what
	
def myfn() :
	print("hello world")


#myfn()
# prints hello world
 	
myfn = foo(myfn)
myfn()
# prints before and then hello world








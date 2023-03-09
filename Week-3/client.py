# Implement a Fibonacci function on a remote server.
# The server is implemented in server.py.

import Pyro.core

# call the remote function from the server
def fib(n):
    return Pyro.core.getProxyForURI("PYROLOC://localhost:7766/fib").fib(n)

# print the first 10 Fibonacci numbers
for i in range(10):
    print fib(i)


# Implement a Fibonacci function on a remote server.
# The server is implemented in server.py.

import Pyro.core

# this is server.py
class Fib(Pyro.core.ObjBase):
    def fib(self, n):
        if n<2:
            return 1
        else:
            return self.fib(n-1) + self.fib(n-2)
        
Pyro.core.initServer()
daemon=Pyro.core.Daemon()
uri=daemon.connect(Fib(),"fib")
print( "The daemon runs on port:",daemon.port)
print ("The object's uri is:",uri)
daemon.requestLoop()

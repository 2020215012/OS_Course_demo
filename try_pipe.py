# -*- coding:utf-8 -*-
# author:skipper 
# date:5/16/23 
# time:7:08 PM 
# software: PyCharm
import os
import subprocess

from cffi.setuptools_ext import execfile

cmd0 = "gcc Message_queue/Talker.c -o Message_queue/Talker"
cmd1 = "Message_queue/Talker"
input_str = "nasndwd"
os.system(cmd0)
a = subprocess.run(cmd1, shell=True, input=input_str.encode(), stdout=subprocess.PIPE)
# print(a.stdout.decode())

cmd2 = "gcc Message_queue/Listener.c -o Message_queue/Listener"
cmd3 = "Message_queue/Listener"
os.system(cmd2)
b = subprocess.getoutput(cmd3)
print(b)
#
# del a, b

# if __name__ == '__main__':
#     input_str = "adiwnaiwd"
#     cmd0 = "gcc Socket/Server.c -o Socket/Server"
#     cmd1 = "Socket/Server"
#     os.system(cmd0)
#     a = subprocess.Popen(cmd1, shell=True, stdout=subprocess.PIPE)
#     cmd2 = "gcc Socket/Client.c -o Socket/Client"
#     cmd3 = "Socket/Client 127.0.0.1"
#     os.system(cmd2)
#     b = subprocess.run(cmd3, shell=True, input=input_str.encode(), stderr=subprocess.PIPE)
#
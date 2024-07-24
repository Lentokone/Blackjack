There was a bit of an error.

gdb) run test
Starting program: C:\Users\Olli\Desktop\f\test\test.exe test
[New Thread 13968.0x4220]
[New Thread 13968.0x4c80]
[New Thread 13968.0x274c]

Thread 1 received signal SIGSEGV, Segmentation fault.
0x000000006fcaac42 in libstdc++-6!_ZNSo6sentryC1ERSo () from C:\Program Files\Neovim\bin\libstdc++-6.dll
(gdb) backtrace
#0  0x000000006fcaac42 in libstdc++-6!_ZNSo6sentryC1ERSo () from C:\Program Files\Neovim\bin\libstdc++-6.dll
#1  0x000000006fcf8e99 in libstdc++-6!_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x ()
   from C:\Program Files\Neovim\bin\libstdc++-6.dll
#2  0x000000006fcfe1f7 in libstdc++-6!_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc ()
   from C:\Program Files\Neovim\bin\libstdc++-6.dll
#3  0x00007ff70c641479 in main ()
(gdb)

I wonder why it was using the libstdc++ from the neovim directory
################################################################################

                        C1 - ASSIGNMENT 3 - ID 1894945

################################################################################

To execute the program type "make" into the terminal (" " are not required) and
hit enter. The program is run through a Makefile, provided in .zip folder, so
that no other commands are needed.
For clarity reasons, every test corrrectly performed by the program is printed
on the terminal runtime: the user can thus have a firmer grip on the operations
that are being performed.
The program has been designed in such a way that other possible tests can be
simply executed by means of a simple change of parameters in the  Makefile: a
suitable check of consistency for the given set of parameters has been inserted
as well and in case a wrong insertion happens a suitable usage-message is
printed on the terminal for the user.
Every time the program is run the arguments have to be inserted in following
order after the "./myprogram" instruction:
"scheme number" "model number" "tau_0" "J"
In particular:
- to test with FE insert 0;
- to test with BE insert 1;
- to test with IM insert 2;
- to test with Heun3 insert 3;
- to test with DIRK2 insert 4.
Moreover:
- model 1 is selected inserting 1;
- model 2 is selected inserting 2;
- test problem is selected by inserting 3.
Along with the success message printed on the terminal everytime the code is
run correctly, the number of calls to f and df for model 1 and tau_0 = 0.1 or
tau_0=0.05 is printed.
4 different plotscripts are provided and the final .tex document is generated
automatically through them by the Makefile.

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
For the choice of the corresponding values the user can consult the assignment
sheet provided.
Along with the success message printed on the terminal everytime the code is
run correctly, the number of calls to f and df for model 1 and tau_0 = 0.1 and
tau_0.05 is printed.
4 different plotscripts are provided and the final .tex document is generated
automatically through them by the Makefile.

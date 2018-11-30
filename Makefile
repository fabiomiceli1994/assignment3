# generated files
#TEX=u1894945-assignment2.tex
#PLOTSCRIPTS=plotscript1.gpl plotscript2.gpl plotscript3.gpl plotscript4.gpl plotscript5
PLOTSCRIPTS=plotscript1.gpl plotscript2.gpl plotscript3.gpl plotscript4.gpl
RESULTS=Errors_Model_1_Scheme_0_tau_0.100000_J_12.dat Errors_Model_2_Scheme_0_tau_0.100000_J_12.dat Errors_Model_1_Scheme_1_tau_0.100000_J_12.dat Errors_Model_2_Scheme_1_tau_0.100000_J_12.dat Errors_Model_1_Scheme_2_tau_0.100000_J_12.dat Errors_Model_2_Scheme_2_tau_0.100000_J_12.dat Errors_Model_1_Scheme_3_tau_0.100000_J_12.dat Errors_Model_2_Scheme_3_tau_0.100000_J_12.dat Errors_Model_1_Scheme_4_tau_0.100000_J_12.dat Errors_Model_2_Scheme_4_tau_0.100000_J_12.dat Error_Model_1_Scheme_0_tau_0.050000.dat Error_Model_1_Scheme_1_tau_0.050000.dat Error_Model_1_Scheme_2_tau_0.050000.dat Error_Model_1_Scheme_3_tau_0.050000.dat Error_Model_1_Scheme_4_tau_0.050000.dat Error_Model_1_Scheme_0_tau_0.100000.dat Error_Model_1_Scheme_1_tau_0.100000.dat Error_Model_1_Scheme_2_tau_0.100000.dat Error_Model_1_Scheme_3_tau_0.100000.dat Error_Model_1_Scheme_4_tau_0.100000.dat
PROGRAM=myprogram
OBJS=main.cc
PLOTS=Err_M1_0.1.pdf Err_M2_0.1.pdf Err_vs_t_0.05.pdf Err_vs_t_0.1.pdf
#PLOTS=Err_FE.pdf Err_BE.pdf Err_IM.pdf Err_Heun3.pdf Err_DIRK2.pdf
#REPORT=u1894945-assignment2.pdf
# additional variables
CPPFLAGS=-std=c++11
#CPPFLAGS=-std=c++11 -g


all: $(PLOTS)

#$(REPORT): $(PLOTS) $(TEX)
	#pdflatex -interaction=batchmode u1894945-assignment2.tex
	#pdflatex -interaction=batchmode u1894945-assignment2.tex

$(PLOTS): $(RESULTS) $(PLOTSCRIPTS)
	gnuplot plotscript1.gpl
	gnuplot plotscript2.gpl
	gnuplot plotscript3.gpl
	gnuplot plotscript4.gpl
	#gnuplot plotscript5.gpl


$(RESULTS): $(PROGRAM)
	./$(PROGRAM) 1 0 0.1 12
	./$(PROGRAM) 2 0 0.1 12
	./$(PROGRAM) 1 1 0.1 12
	./$(PROGRAM) 2 1 0.1 12
	./$(PROGRAM) 1 2 0.1 12
	./$(PROGRAM) 2 2 0.1 12
	./$(PROGRAM) 1 3 0.1 12
	./$(PROGRAM) 2 3 0.1 12
	./$(PROGRAM) 1 4 0.1 12
	./$(PROGRAM) 2 4 0.1 12
	# ./$(PROGRAM) 3 1 0.1 12
	# ./$(PROGRAM) 3 2 0.1 12
	# ./$(PROGRAM) 3 3 0.1 12
	# ./$(PROGRAM) 3 4 0.1 12
	# ./$(PROGRAM) 3 1 0.5 12
	# ./$(PROGRAM) 3 2 0.5 12
	# ./$(PROGRAM) 3 3 0.5 12
	# ./$(PROGRAM) 3 4 0.5 12

#g++ -O3 -Wall -Wfatal-errors -pedantic $(CPPFLAGS) $(OBJS) -o $(PROGRAM)
$(PROGRAM): $(OBJS)
	g++ -Ofast -Wall -Wfatal-errors -pedantic $(CPPFLAGS) $(OBJS) -o $(PROGRAM)


#g++ -O3 -Wall -Wfatal-errors -pedantic $(CPPFLAGS) -c $^ -o $@
# $(OBJS): %.o: %.cc
# 	g++ -Ofast -Wall -Wfatal-errors -pedantic $(CPPFLAGS) -c $^ -o $@

clean:
	rm -rf $(PROGRAM) $(RESULTS)

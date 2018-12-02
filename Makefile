# generated files
TEX=u1894945-assignment3.tex
PLOTSCRIPTS=plotscript1.gpl plotscript2.gpl plotscript3.gpl plotscript4.gpl
RESULTS=EOCS_Model_1_Scheme_0_tau_0.100000_J_12.dat EOCS_Model_2_Scheme_0_tau_0.100000_J_12.dat EOCS_Model_1_Scheme_1_tau_0.100000_J_12.dat EOCS_Model_2_Scheme_1_tau_0.100000_J_12.dat EOCS_Model_1_Scheme_2_tau_0.100000_J_12.dat EOCS_Model_2_Scheme_2_tau_0.100000_J_12.dat EOCS_Model_1_Scheme_3_tau_0.100000_J_12.dat EOCS_Model_2_Scheme_3_tau_0.100000_J_12.dat EOCS_Model_1_Scheme_4_tau_0.100000_J_12.dat EOCS_Model_2_Scheme_4_tau_0.100000_J_12.dat Error_Model_1_Scheme_0_tau_0.050000.dat Error_Model_1_Scheme_1_tau_0.050000.dat Error_Model_1_Scheme_2_tau_0.050000.dat Error_Model_1_Scheme_3_tau_0.050000.dat Error_Model_1_Scheme_4_tau_0.050000.dat Error_Model_1_Scheme_0_tau_0.100000.dat Error_Model_1_Scheme_1_tau_0.100000.dat Error_Model_1_Scheme_2_tau_0.100000.dat Error_Model_1_Scheme_3_tau_0.100000.dat Error_Model_1_Scheme_4_tau_0.100000.dat
PROGRAM=myprogram
OBJS=main.cc
PLOTS=ME_M1.pdf ME_M2.pdf Err_vs_t_05.pdf Err_vs_t_1.pdf
REPORT=u1894945-assignment3.pdf
# additional variables
CPPFLAGS=-std=c++11
#CPPFLAGS=-std=c++11 -g


all: $(REPORT)

$(REPORT): $(PLOTS) $(TEX)
	pdflatex -interaction=batchmode u1894945-assignment3.tex
	pdflatex -interaction=batchmode u1894945-assignment3.tex

$(PLOTS): $(RESULTS) $(PLOTSCRIPTS)
	gnuplot plotscript1.gpl
	gnuplot plotscript2.gpl
	gnuplot plotscript3.gpl
	gnuplot plotscript4.gpl


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

#g++ -Ofast -Wall -Wfatal-errors -pedantic $(CPPFLAGS) $(OBJS) -o $(PROGRAM)
#g++ -O1 -Wall -Wfatal-errors -pedantic $(CPPFLAGS) $(OBJS) -o $(PROGRAM)
$(PROGRAM): $(OBJS)
	g++ -Ofast -Wall -Wfatal-errors -pedantic $(CPPFLAGS) $(OBJS) -o $(PROGRAM)



#g++ -O3 -Wall -Wfatal-errors -pedantic $(CPPFLAGS) -c $^ -o $@
# $(OBJS): %.o: %.cc
# 	g++ -Ofast -Wall -Wfatal-errors -pedantic $(CPPFLAGS) -c $^ -o $@

clean:
	rm -rf $(PROGRAM) $(RESULTS)

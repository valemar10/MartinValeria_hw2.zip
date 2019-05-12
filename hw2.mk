Resultados_hw2.pdf : Resultados_hw2.tex signals.pdf Fourier_trans.pdf Temblor.pdf Fourier_temblor.pdf espectograma_temblor.pdf espectograma.pdf plot_omegafijo.pdf plot_omegas.pdf plot_omega1.pdf plot_omega2.pdf plot_omega3.pdf plot_omega4.pdf gammas.pdf masas.pdf gammas1.pdf gammas2.pdf masas1.pdf masas2.pdf
	pdflatex Resultados_hw2.tex
signals.pdf: Fourier.py
	python Fourier.py
Fourier_trans.pdf: Fourier.py
	python Fourier.py
espectograma.pdf: Fourier.py
	python Fourier.py
Temblor.pdf: Fourier.py
	python Fourier.py
Fourier_temblor.pdf: Fourier.py
	python Fourier.py
espectograma_temblor.pdf: Fourier.py
	python Fourier.py
plot_omegafijo.pdf: Plots_hw2.py datoslp.dat
	python Plots_hw2.py
datoslp.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
plot_omegas.pdf: Plots_hw2.py datos_omega.dat
	python Plots_hw2.py
datos_omega.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
plot_omega1.pdf: Plots_hw2.py datoslp1.dat
	python Plots_hw2.py
datoslp1.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
plot_omega2.pdf: Plots_hw2.py datoslp2.dat
	python Plots_hw2.py
datoslp2.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp    
plot_omega3.pdf: Plots_hw2.py datoslp3.dat
	python Plots_hw2.py
datoslp3.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
gammas.pdf: Plots_hw2.py gamma.dat
	python Plots_hw2.py
gamma.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
gammas1.pdf: Plots_hw2.py gamma2.dat
	python Plots_hw2.py
gamma2.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
gammas2.pdf: Plots_hw2.py gamma3.dat
	python Plots_hw2.py
gamma3.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
masas.pdf: Plots_hw2.py masa.dat
	python Plots_hw2.py
masa.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
masas1.pdf: Plots_hw2.py masa1.dat
	python Plots_hw2.py
masa1.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
masas2.pdf: Plots_hw2.py masa2.dat
	python Plots_hw2.py
masa2.dat : a.out
	./a.out
a.out : Edificio.cpp
	g++ Edificio.cpp
default: pdf clean
all: clean pdf clean

pdf: clean SFST-Manual.pdf SFST-Tutorial.pdf

%.pdf: %.tex
	pdflatex $<
clean:
	rm -f *.log *.aux *.bbl *.dvi


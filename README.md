
# SFST - Stuttgart Finite State Transducer


|      CI              | status |
|----------------------|--------|
| CMake builds           | [![CMake Actions Status][actions-cmake-badge]][actions-cmake-link] |
| Pip builds           | [![Pip Actions Status][actions-pip-badge]][actions-pip-link] |
| Wheels builds           | [![Wheels Actions Status][actions-wheels-badge]][actions-wheels-link] |

[actions-cmake-link]:        https://github.com/santhoshtr/sfst/actions?query=workflow%3A%22CMake
[actions-pip-link]:        https://github.com/santhoshtr/sfst/actions?query=workflow%3A%22Pip
[actions-wheels-link]:        https://github.com/santhoshtr/sfst/actions?query=workflow%3A%22Wheels
[actions-cmake-badge]:       https://github.com/santhoshtr/sfst/workflows/CMake/badge.svg
[actions-pip-badge]:       https://github.com/santhoshtr/sfst/workflows/Pip/badge.svg
[actions-wheels-badge]:       https://github.com/santhoshtr/sfst/workflows/Wheels/badge.svg

## Installation

SFST can be compiled in Unix/Linux, Windows and Mac operating systems.

The SFST command line utilities has a few external requirements.

 1. The "Flex" scanner generator which can be downloaded from: https://github.com/westes/flex. In linux systems they can be installed using package manager. For example, in Ubuntu, `apt install flex` installs it.
 2. The "Bison" parser generator available from http://www.gnu.org/software/bison. In linux systems they can be installed using package manager. For example, in Ubuntu, `apt install bison` installs it.

After unpacking the software package, in the top directory of source code,

```
mkdir build
cd build
cmake ..
make
```

to compile the tools. Then call

```
make install
```

to install the tools in /usr/local/bin. Change the variable DESTDIR
in Makefile if you want to install to a different directory.
Finally call

```
make maninstall
```

to install the manpages in /usr/local/man/man1 and you are done.

The subdirectory data contains a simple example of an English
morphological analyser, the source code of the German SMOR morphology
(with just a few sample lexicon entries), and the general morphology
XMOR which may be used as a starting point for the development of a
computational morphology.

## Usage

See the manual SFST-Manual.pdf in the doc subdirectory and the man
pages for more information on the SFST tools. doc/SFST-Tutorial.pdf
explains how computational morphologies are implemented in SFST.

If you want to implement your own tools based on the SFST code, have a
look at fst-infl.C and fst-infl2.C. They show how analysers are
implemented with the standard (fst-infl) and the compact (fst-infl2)
transducer format.

## Author

The SFST tools have been implemented by Helmut Schmid, Institute for
Computational Linguistics, University of Stuttgart, Germany and they
are available under the GNU public license version 2 or higher.

Please cite the following publication if you want to refer to the SFST tools:

`A Programming Language for Finite State Transducers, Proceedings of the 5th International Workshop on Finite State Methods in Natural Language Processing (FSMNLP 2005), Helsinki, Finland.` [pdf](https://www.cis.uni-muenchen.de/~schmid/papers/SFST-PL.pdf)

## Bug reports

Please send bug reports and other feedback to schmid@cis.lmu.de.

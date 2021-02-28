#include <pybind11/pybind11.h>

#include "../src/fst.h"

using namespace SFST;

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j)
{
    return i + j;
}

int analyse(){
    FILE *file;

    file = stdin;
    if (file == NULL)
    {
        printf("Please provide input file");
        exit(1);
    }
    try {
        Transducer a(file);
        fclose(file);
        std::cout << "ok";
    }
  catch (const char *p) {
    std::cerr << p << "\n";
    return 1;
  }

    return 0;
}

namespace py = pybind11;

PYBIND11_MODULE(pysfst, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def(
        "subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("analyse", &analyse, R"pbdoc(
        Analyse two numbers

        Some other explanation about the analyse function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

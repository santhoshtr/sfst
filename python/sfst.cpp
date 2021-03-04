#include <pybind11/pybind11.h>
#include <sstream>

#include "../src/fst.h"

using namespace SFST;

const int GENERATE_MODE = 1;
const int ANALYSE_MODE = 2;

Transducer *transducer;

/*
 * Use the transducer (either in generate- or in analyse-mode) to rewrite the
 * input string (GENERATE_MODE, ANALYSE_MODE). This function is not directly
 * callable from Python.
 * Because of peculiarities in the implementation of SFST it is not possible
 * to access the output of the analyse_string/generate_string directly. As a
 * workaround the result is written into a file and afterwards read out.
 */
const char *transduce(char input[], int mode)
{
    FILE *temp_file = std::tmpfile();

    // Analyse or generate transducer output and write to file
    if (mode == ANALYSE_MODE)
    {
        transducer->analyze_string(input, temp_file, true);
    }
    else if (mode == GENERATE_MODE)
    {
        transducer->generate_string(input, temp_file, true);
    }
    std::rewind(temp_file);
    // Read transducer output from file
    char c;
    std::ostringstream oss(std::ostringstream::out);
    c = fgetc(temp_file);
    while (c != EOF)
    {
        oss.put(c);
        c = fgetc(temp_file);
    }
    fclose(temp_file);

    return oss.str().c_str();
}

/**
 * Initialize transducer.
 */
void init(char *transducer_filename)
{
    if (transducer_filename == NULL)
    {
        printf("Please provide transducer file");
        exit(1);
    }
    FILE *transducer_file;
    transducer_file = fopen(transducer_filename, "rb");
    if (transducer_file != NULL)
    {
        transducer = new Transducer(transducer_file);
        fclose(transducer_file);
    }
    else
    {
        perror("Could not read transducer file");
        exit(1);
    }
}

/*
 * Destroys the transducer object.
 * args: None
 */
void delete_transducer()
{
    delete transducer;
}

const char *analyse(char *analysis_input)
{
    return transduce(analysis_input, ANALYSE_MODE);
}

const char *generate(char *generate_input)
{
    return transduce(generate_input, GENERATE_MODE);
}

namespace py = pybind11;

PYBIND11_MODULE(sfst, m)
{
    m.def("init", &init, R"pbdoc(
        Initialize transducer

        Some other explanation about the analyse function.
    )pbdoc");

    m.def("analyse", &analyse, R"pbdoc(
        Analyse a string

        Some other explanation about the analyse function.
    )pbdoc");

    m.def("generate", &generate, R"pbdoc(
        Generate a string

        Some other explanation about the generate function.
    )pbdoc");

    m.def("delete", &delete_transducer, R"pbdoc(
        Delete the transducer instance

        Some other explanation about the generate function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

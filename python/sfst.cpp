#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <sstream>

#include "../src/fst.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

using namespace SFST;

const int GENERATE_MODE = 1;
const int ANALYSE_MODE = 2;

Transducer *transducer;

/**
 * Initialize transducer.
 */
void init(char *transducer_filename) {
  if (transducer_filename == NULL) {
    printf("Please provide transducer file");
    exit(1);
  }
  FILE *transducer_file;
  transducer_file = fopen(transducer_filename, "rb");
  if (transducer_file != NULL) {
    transducer = new Transducer(transducer_file);
    fclose(transducer_file);
  } else {
    perror("Could not read transducer file");
    exit(1);
  }
}

/*
 * Destroys the transducer object.
 * args: None
 */
void delete_transducer() { delete transducer; }

const vector<std::string> analyse(char *input) {
  return transducer->analyze_string(input, true);
}

const vector<std::string> generate(char *input) {
  return transducer->generate_string(input, true);
}

namespace py = pybind11;

PYBIND11_MODULE(sfst, m) {
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

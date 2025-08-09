#include "sfst_wrapper.h"
#include "../src/fst.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace SFST;

static Transducer *transducer = nullptr;

extern "C" {

int sfst_init(const char *filename) {
  if (filename == nullptr) {
    return 1;
  }

  // Clean up existing transducer
  if (transducer != nullptr) {
    delete transducer;
    transducer = nullptr;
  }

  FILE *transducer_file = fopen(filename, "rb");
  if (transducer_file == nullptr) {
    return 2;
  }

  try {
    transducer = new Transducer(transducer_file);
    fclose(transducer_file);
    return 0;
  } catch (...) {
    fclose(transducer_file);
    return 3;
  }
}

void sfst_cleanup() {
  if (transducer != nullptr) {
    delete transducer;
    transducer = nullptr;
  }
}

char **sfst_analyse(const char *input, int *result_count) {
  if (transducer == nullptr || input == nullptr || result_count == nullptr) {
    *result_count = 0;
    return nullptr;
  }

  try {
    std::vector<std::string> results =
        transducer->analyze_string(const_cast<char *>(input), true);
    *result_count = static_cast<int>(results.size());

    if (results.empty()) {
      return nullptr;
    }

    char **c_results =
        static_cast<char **>(malloc(results.size() * sizeof(char *)));
    if (c_results == nullptr) {
      *result_count = 0;
      return nullptr;
    }

    for (size_t i = 0; i < results.size(); i++) {
      size_t len = results[i].length() + 1;
      c_results[i] = static_cast<char *>(malloc(len));
      if (c_results[i] == nullptr) {
        // Clean up on allocation failure
        for (size_t j = 0; j < i; j++) {
          free(c_results[j]);
        }
        free(c_results);
        *result_count = 0;
        return nullptr;
      }
      strcpy(c_results[i], results[i].c_str());
    }

    return c_results;
  } catch (...) {
    *result_count = 0;
    return nullptr;
  }
}

char **sfst_generate(const char *input, int *result_count) {
  if (transducer == nullptr || input == nullptr || result_count == nullptr) {
    *result_count = 0;
    return nullptr;
  }

  try {
    std::vector<std::string> results =
        transducer->generate_string(const_cast<char *>(input), true);
    *result_count = static_cast<int>(results.size());

    if (results.empty()) {
      return nullptr;
    }

    char **c_results =
        static_cast<char **>(malloc(results.size() * sizeof(char *)));
    if (c_results == nullptr) {
      *result_count = 0;
      return nullptr;
    }

    for (size_t i = 0; i < results.size(); i++) {
      size_t len = results[i].length() + 1;
      c_results[i] = static_cast<char *>(malloc(len));
      if (c_results[i] == nullptr) {
        // Clean up on allocation failure
        for (size_t j = 0; j < i; j++) {
          free(c_results[j]);
        }
        free(c_results);
        *result_count = 0;
        return nullptr;
      }
      strcpy(c_results[i], results[i].c_str());
    }

    return c_results;
  } catch (...) {
    *result_count = 0;
    return nullptr;
  }
}

void sfst_free_results(char **results, int count) {
  if (results == nullptr) {
    return;
  }

  for (int i = 0; i < count; i++) {
    if (results[i] != nullptr) {
      free(results[i]);
    }
  }
  free(results);
}
}

#ifndef SFST_WRAPPER_H
#define SFST_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize the transducer from a file.
 * Returns 0 on success, non-zero on error.
 */
int sfst_init(const char *filename);

/**
 * Cleanup the transducer and free memory.
 */
void sfst_cleanup();

/**
 * Analyze a string and return results.
 * result_count will be set to the number of results.
 * Returns array of strings that must be freed with sfst_free_results.
 */
char **sfst_analyse(const char *input, int *result_count);

/**
 * Generate a string and return results.
 * result_count will be set to the number of results.
 * Returns array of strings that must be freed with sfst_free_results.
 */
char **sfst_generate(const char *input, int *result_count);

/**
 * Free the results returned by sfst_analyse or sfst_generate.
 */
void sfst_free_results(char **results, int count);

#ifdef __cplusplus
}
#endif

#endif

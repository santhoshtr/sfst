# Python bindings for SFST

This is python binding for SFST. The `sfst` python library can be imported and can be used for analysis and generation as explained in the below examples:

## Installation

`sfs` python library is available at pypi.org. It can be installed as follows:

```bash
pip install sfst
```

## Import and initialize

```python
import sfst
# Initialize with the compiled sfst.
sfst.init('path/to/fst.a'))
```

Initialization is must before doing any operations.

## Analysis

```python
import sfst
# Initialize with the compiled sfst.
sfst.init('path/to/fst.a'))
# Analyse a string. results are a list of analysis.
analysis_results = sfst.analyse("easier")
# Returns ['easy<ADJ><comp>'] for example.
```

## Generation

```python
import sfst
# Initialize with the compiled sfst.
sfst.init('path/to/fst.a'))
# Generate a string. results are a list of analysis.
generate_results = sfst.generate("easy<ADJ><comp>")
# Returns ['easier'] for example.
```

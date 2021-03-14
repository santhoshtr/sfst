import os
import sfst
import os

CURR_DIR = os.path.abspath(os.path.dirname(os.path.realpath(__file__)))

print("SFST version " + sfst.__version__)
sfst.init(os.path.join(CURR_DIR, 'easy.a'))
analysis_results = sfst.analyse("easy")
assert len(analysis_results) == 1
assert analysis_results[0] == 'easy<ADJ><pos>'
generate_results = sfst.generate("easy<ADJ><comp>")
assert len(generate_results) == 1
assert generate_results[0] == 'easier'

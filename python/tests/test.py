import os
os.environ['LD_LIBRARY_PATH'] = os.getcwd()
import sfst
import pathlib
import os

assert sfst.__version__ == 'dev'
sfst.init( os.path.join(pathlib.Path(__file__).parent, "easy.a"))
assert sfst.analyse("easy") == 'easy<ADJ><pos>\n'
assert sfst.generate("easy<ADJ><pos>") == 'easy\n'
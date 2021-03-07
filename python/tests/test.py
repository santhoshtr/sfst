import os
import sfst
import pathlib
import os

print("SFST version " + sfst.__version__)
sfst.init( os.path.join(pathlib.Path(__file__).parent, "easy.a"))
assert sfst.analyse("easy") == 'easy<ADJ><pos>\n'
assert sfst.generate("easy<ADJ><pos>") == 'easy\n'
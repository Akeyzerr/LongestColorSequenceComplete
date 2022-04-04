from ctypes import *
import pathlib

LIBRARY_PATH = pathlib.Path().absolute() / "liblongestSequence.dylib"

ext_lib = CDLL(LIBRARY_PATH)

ext_lib.main.argtypes = [
    c_int,
    POINTER(c_char_p),
]

strings = [f'../tests/test_{i}' for i in range(6)]
arr = (c_char_p * len(strings))()
arr[:] = [s.encode('utf-8') for s in strings]

if __name__ == "__main__":
    print(ext_lib.main(5, arr))

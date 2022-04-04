from distutils.core import setup, Extension


def main():
    setup(
        name="Longest Color Sequence",
        version="0.1.18",
        long_description="Given a grid with different colors in a different cell, each color represented by a different char (R, G, B) returns the largest connected component on the grid.",
        author="Angel Toporchev",
        ext_modules=[Extension("LonColSeq", [
            "./src/lcsModule.c",
            "../lcs/src/helpers.c",
            "../lcs/src/runDFS.c",
            "../lcs/src/Vector.c",
        ], include_dirs=["../lcs/lib"])]
    )


if (__name__ == "__main__"):
    main()

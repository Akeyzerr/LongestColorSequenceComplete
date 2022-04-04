from setting import *


def compare(fn_prod, fn_expected):
    with open(join(TESTS, fn_prod), "r") as produced:
        with open(join(TESTS, OUT, fn_expected), "r") as expected:
            for i, (exp, prod) in enumerate(zip(expected, produced)):
                prd = "".join([x for x in prod.lstrip()
                              if x.isdigit() or x.isupper()])
                out = "".join([x for x in exp if x.isdigit() or x.isupper()])
                print("    Line " + str(i), "MATCH" if prd ==
                      out else "NO MATCH")
                try:
                    assert(prd == out)
                    print(f"Produced::\t{prod.lstrip().rstrip()}")
                except AssertionError:
                    print(f"Expected ::\t{exp.lstrip().rstrip()}")
                    print(f"Produced ::\t{prod.lstrip().rstrip()}")


if __name__ == "__main__":
    compare(RES_OUTPT, TEST_OUTPT)

from setting import *


def run_test(filename=TEST_INPUT):
    with open(join(TESTS, OUT, filename), mode="r") as input_str:
        print(*input_str)


if __name__ == '__main__':
    run_test()

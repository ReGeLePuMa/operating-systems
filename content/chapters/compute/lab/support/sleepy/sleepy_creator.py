import subprocess
from sys import exit
from time import *
import os
NUM_SLEEPS = 10


def main():
    # TODO 1: create 10 `sleep 1000` processes using `subprocess.Popen`
    # Use the documentation: https://docs.python.org/3/library/subprocess.html#subprocess.Popen
    for i in range(10):
        subprocess.Popen(args=['sleep','1000'],env={'PATH':os.getenv('PATH')})
        sleep(3)
        subprocess.Popen(args=['killall','sleep'],env={'PATH':os.getenv('PATH')})
    # TODO 2: Make this script also wait for 1000 seconds. Use `sleep` from the
    # `time` module.
    sleep(3)
    pass


if __name__ == "__main__":
    exit(main())

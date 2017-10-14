#!/usr/bin/python3

import sys

print('\n'.join(sorted(sys.stdin.read().split('\n')[:-1], key=lambda x: int(''.join(x.split()[0:2])))))


#!/usr/bin/python3

import sys

def main():
    # Ensure correct amount of arguments were set
    if len(sys.argv) != 3:
        print('Not the correct amount of arguments!');
        sys.exit(1)

    # Read input file
    with open(sys.argv[1], 'r') as f:
        lines = f.read().split('\n')

    # Parse gap
    gap = int(sys.argv[2])

    # Loop through input lines
    for line in lines[1:-1]:
        d = {int(value): distance for distance, value in enumerate(line.split())}
        print(sum(map(lambda x: abs(d[x + gap] - d[x]), filter(lambda x: (x + gap) in d, d))))

if __name__ == '__main__':
    main()


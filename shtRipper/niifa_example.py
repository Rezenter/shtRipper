from shtRipper import shtRipper

print('example')

signals = shtRipper.extract_niifa('../in', 38654)

names = signals.keys()

print(names)

i_want = 'Ivfc'

print(signals[i_want])

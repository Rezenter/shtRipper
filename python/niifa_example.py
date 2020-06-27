from python import niifaRipper

print('example')

signals = niifaRipper.extract('../in', 38654)

names = signals.keys()

print(names)

i_want = 'Ivfc'

print(signals[i_want])

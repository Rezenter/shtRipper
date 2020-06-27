import struct

print('niifa ripper alive')

encoding = 'utf-8'

def extract(path, shotn):
    if path is None or type(path) != str or len(path) == 0:
        fuck  # i dont know .dat files path yet
        import urllib
        from smb.SMBHandler import SMBHandler
        opener = urllib.request.build_opener(SMBHandler)
        print('Connecting to remote...')
        file = opener.open('smb://guest:Globus-M@172.16.12.127/Data/sht%d.SHT' % shotn)
    else:
        file = open('%s/000%d.dat' % (path, shotn), 'rb')
    data = file.read()
    file.close()

    start = data.find(bytes('t_ms', encoding=encoding))
    stop = data.find(bytes('\n', encoding=encoding), start)
    stop += 1

    names = [entry.decode('utf-8') for entry in data[start: stop - 1].split(bytes(' ', encoding=encoding))]

    result = {}
    for signal in names:
        result[signal] = []
    slice_format = '%df' % len(names)
    slice_size = 4 * len(names)

    for time in range(int((len(data) - stop)/4/len(names))):
        time_slice = struct.unpack(slice_format, data[stop: stop + slice_size])
        stop += slice_size
        for signal in range(len(names)):
            result[names[signal]].append(time_slice[signal])

    return result

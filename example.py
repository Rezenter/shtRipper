import ripper

data, link = ripper.extract('', 38516, ['^i', 'SXR'])

print(list(data.keys()), link)

data_all = ripper.extract('in', 38516)  # extract all charts of 38516 discharge in relative path 'in'

for diag in data_all:
    print(data_all[diag]['name'])

x, y = ripper.x_y(data_all[17])  # convert data to (x, y) format
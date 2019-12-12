import ripper

data = ripper.extract('', 38516, [17])  # extract only 17th (from zero) chart of 38516 discharge in relative path 'in'

#data_all = ripper.extract('in', 38516)  # extract all charts of 38516 discharge in relative path 'in'

#for diag in data_all:
#    print(data_all[diag]['name'])

#data = ripper.extract('/home/nz/Code/shtRipper/in', 38516) # same with absolute path


ripper.plot_hist(data[17])  # plot 17th chart

#x, y = ripper.x_y(data[17])  # convert data to (x, y) format
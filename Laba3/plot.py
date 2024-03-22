import os
import matplotlib.pyplot as plt

sort_algorythm_names = []
num_of_elements = []
time_microsec = []

for sort_name in os.listdir('sorting_results'):
    sort_algorythm_names.append(sort_name)
    with open(f'sorting_results/{sort_name}/time1.txt', 'r') as file:
        data = file.readlines()
        num_of_elements.append([int(line.split()[0])*50 for line in data])
        time_microsec.append([float(line.split()[1]) for line in data])

for i in range(len(sort_algorythm_names)):
    plt.plot(num_of_elements[i], time_microsec[i], label=sort_algorythm_names[i])


plt.title('Сравнение квадратичных и не совсем сортировок')

plt.xlabel('Число элементов, штук')
plt.ylabel('Время, микросекунд')
plt.legend()
plt.grid(True)

plt.savefig('plot.png')

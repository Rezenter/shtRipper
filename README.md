# shtRipper

Код для извлечения данных из .sht файлов.

## install

Для использования достаточно поместить файл ripper.py в дерево Вашего проекта и импортировать его.

## usage

Пример базового использования приведён в файле example.py

Необходимо импортирование файла:

    import ripper
    
Далее отдаётся команда на чтение и распаковку файла:
    
    var = ripper.extract(path, shotn, request)
    
- _var_ - словарь, в котором ключами являются номера сигналов в файле, а значениями - словарь следующей структуры:
 - type - число, хранящее тип структуры данных.
 - name - строка, содержит имя сигнала. Указано в _Combiscope_ в заголовке графика до ";".
 - comm - строка, комментарий к сигналу, содержит номер и канал ацп, номер разряда. Указано в _Combiscope_ в заголовке графика после ";".
 - unit - строка, подпись оси ординат.
 - time - словарь, содержит время создания .sht.
 - #ch - число, содержит число каналов в сигнале, необходимо для разархивирования.
 - tMin - число, минимум по шкале времени.
 - tMax - число, максимум по шкале времени.
 - uMin - число, описывает смещение данных по шкале ординат.
 - delta - число, описывает амплитуду сигнала.
 - data - массив, содержит в себе сигнал. В зависимости от _type_ может содержать только ординаты, пары XY или тройки XYErr.
- _path_ - строка, путь к файлу .sht.
- _shotn_ - число, номер разряда.
- _request_ - список чисел, (опционально) передаётся список номеров сигналов для разархивирования. Без третьего аргумента производится полная, долгая разархивация.

структура _time_:
 * year - число, год.
 * month - число, номер месяца от 1 до 12.
 * weekDay - число, день недели (0 = вс, 1 = пн, ... 6 = сб).
 * monthDay - число, день месяца.
 * hour - число, час.
 * minute - число, минута.
 * second - число, секунда.
 * mSecond - число, миллисекунда.
 
Далее можно построить график отдельно выбранного сигнала:
    
    ripper.plot_hist(data[17])

и преобразовать сигнал в вид двух массивов (x_y):

    x, y = ripper.x_y(data[17])
.
# ----------------------------- parallelepiped.py ------------------------------
#  Содержит все методы для взаимодействия с параллелепипедом.
# -------------------------------------------------------------------------
import random
from utils import is_correct


# Чтение данных о параллелепипеда из файла
def read(parallelepiped, str_array, i):
    if i >= len(str_array) - 3:
        return 0
    # добавляет наименование фигуры
    parallelepiped.append("parallelepiped")
    # добавляет длину стороны фигуры
    if is_correct(str_array[i]):
        parallelepiped.append(int(str_array[i]))
    # добавляет длину стороны фигуры
    if is_correct(str_array[i + 1]):
        parallelepiped.append(int(str_array[i + 1]))
        # добавляет длину стороны фигуры
    if is_correct(str_array[i + 2]):
        parallelepiped.append(int(str_array[i + 2]))
    # добавляет плотность материала фигуры
    if is_correct(str_array[i + 3]):
        parallelepiped.append(int(str_array[i + 3]))
    i += 4
    return i


# Генерирует сферу с переменными в пределах от 1 до 30
def rnd(parallelepiped):
    parallelepiped.append("parallelepiped")
    # Добавляет стороны и плотность фигуры
    for i in range(4):
        parallelepiped.append(random.randint(1, 30))


# Выводит информацию о фигуре в консоль
def print_info(parallelepiped):
    print(f"Parallelepiped: a = {parallelepiped[1]}, b = {parallelepiped[2]},"
          f" c = {parallelepiped[3]}; Density = {parallelepiped[4]}; SurfaceArea = {surface_area(parallelepiped)}")


# Выводит информацию о фигуре в файл
def write(parallelepiped, ostream):
    ostream.write(f"Parallelepiped: a = {parallelepiped[1]}, b = {parallelepiped[2]},"
                  f" c = {parallelepiped[3]}; Density = {parallelepiped[4]}; SurfaceArea = {surface_area(parallelepiped)}\n")


# Выводит информацию о фигуре для тестового файла
def write_short(parallelepiped, ostream):
    ostream.write(f"3\n{parallelepiped[1]} {parallelepiped[2]} {parallelepiped[3]} {parallelepiped[4]}")


# Вычисляет площадь поверности параллелепипеда
def surface_area(parallelepiped):
    return 2 * float(parallelepiped[1] * parallelepiped[2] + parallelepiped[1] * parallelepiped[3] + parallelepiped[3] *
                     parallelepiped[2])

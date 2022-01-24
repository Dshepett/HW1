# ----------------------------- sphere.py ------------------------------
#  Содержит все методы для взаимодействия со сфеорой.
# -----------------------------------------------------------------------
import math
import random
from utils import is_correct


# Чтение данных о сфере из файла
def read(sphere, str_array, i):
    if i >= len(str_array) - 1:
        return 0
    # добавляет наименование фигуры
    sphere.append("sphere")
    # добавляет радиус фигуры
    if is_correct(str_array[i]):
        sphere.append(int(str_array[i]))
    # добавляет плотность материала фигуры
    if is_correct(str_array[i + 1]):
        sphere.append(int(str_array[i + 1]))
    i += 2
    return i


# Генерирует сферу с переменными в пределах от 1 до 30
def rnd(sphere):
    # добавляет плотность материала фигуры
    sphere.append("sphere")
    # добавляет радиус фигуры
    sphere.append(random.randint(1, 30))
    # добавляет плотность материала фигуры
    sphere.append(random.randint(1, 30))


# Выводит информацию о фигуре в консоль
def print_info(sphere):
    print(f"Sphere: r = {sphere[1]}; Density = {sphere[2]}; SurfaceArea = {surface_area(sphere)}")


# Выводит информацию о фигуре в файл
def write(sphere, ostream):
    ostream.write(f"Sphere: r = {sphere[1]}; Density = {sphere[2]}; SurfaceArea = {surface_area(sphere)}\n")


# Выводит информацию о фигуре для тестового файла
def write_short(sphere, ostream):
    ostream.write(f"1\n{sphere[1]} {sphere[2]}")


# Вычисляет площадь поверности шара
def surface_area(sphere):
    return float(4 * math.pi * (sphere[1] ** 2))

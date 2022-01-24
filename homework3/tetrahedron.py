# ----------------------------- tetrahedron.py ------------------------------
#  Содержит все методы для взаимодействия со сфеорой.
# ---------------------------------------------------------------------------
import math
import random
from utils import is_correct


# Чтение данных о тетраэдре из файла
def read(tetrahedron, str_array, i):
    if i >= len(str_array) - 1:
        return 0
    # добавляет наименование фигуры
    tetrahedron.append("tetrahedron")
    # добавляет длину ребра фигуры
    if is_correct(str_array[i]):
        tetrahedron.append(int(str_array[i]))
    # добавляет плотность материала фигуры
    if is_correct(str_array[i + 1]):
        tetrahedron.append(int(str_array[i + 1]))
    i += 2
    return i


# Генерирует тетраэдр с переменными в пределах от 1 до 30
def rnd(tetrahedron):
    # добавляет наименование фигуры
    tetrahedron.append("tetrahedron")
    # добавляет длину ребра фигуры
    tetrahedron.append(random.randint(1, 30))
    # добавляет плотность материала фигуры
    tetrahedron.append(random.randint(1, 30))


# Выводит информацию о фигуре в консоль
def print_info(tetrahedron):
    print(f"Tetrahedron: a = {tetrahedron[1]}; "
          f"Density = {tetrahedron[2]}; SurfaceArea = {surface_area(tetrahedron)}")


# Выводит информацию о фигуре в файл
def write(tetrahedron, ostream):
    ostream.write(f"Tetrahedron: a = {tetrahedron[1]};"
                  f" Density = {tetrahedron[2]}; SurfaceArea = {surface_area(tetrahedron)}\n")


# Выводит информацию о фигуре для тестового файла
def write_short(tetrahedron, ostream):
    ostream.write(f"2\n{tetrahedron[1]} {tetrahedron[2]}")


# Вычисляет площадь поверности тетраэра
def surface_area(tetrahedron):
    return math.sqrt(3) * (tetrahedron[1] ** 2)

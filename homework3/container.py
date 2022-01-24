# ----------------------------- container.py ------------------------------
#  Содержит все методы для взаимодействия с контейнером
# -----------------------------------------------------------------------
from random import randint
from utils import is_correct
import sphere
import tetrahedron
import parallelepiped


# Чтение данных о всех фигурах из файла
def read(container, str_array):
    length = len(str_array)
    i = 0
    figures = 0
    while i < length:
        if not is_correct(str_array[i]):
            return -1
        key = int(str_array[i])
        if key == 1:
            i += 1
            sph = []
            i = sphere.read(sph, str_array, i)
            if len(sph) != 3:
                return -1
            container.append(sph)
        elif key == 2:
            i += 1
            tetr = []
            i = tetrahedron.read(tetr, str_array, i)
            if len(tetr) != 3:
                return -1
            container.append(tetr)
        elif key == 3:
            i += 1
            parall = []
            i = parallelepiped.read(parall, str_array, i)
            if len(parall) != 5:
                return -1
            container.append(parall)
        else:
            return -1
    if i == 0:
        return -1
    return figures + 1


# Генерирует фигуры
def rnd(container, length):
    for i in range(length):
        key = randint(1, 3)
        if key == 1:
            sph = []
            sphere.rnd(sph)
            container.append(sph)
        elif key == 2:
            tetr = []
            tetrahedron.rnd(tetr)
            container.append(tetr)
        elif key == 3:
            parall = []
            parallelepiped.rnd(parall)
            container.append(parall)


# Выводит информацию о всех фигурах в консоль
def print_info(container):
    print(f"Container stores {len(container)} shapes:\n")
    for shape in container:
        if shape[0] == "sphere":
            sphere.print_info(shape)
        elif shape[0] == "tetrahedron":
            tetrahedron.print_info(shape)
        elif shape[0] == "parallelepiped":
            parallelepiped.print_info(shape)
        else:
            print(f"Incorrect figure: {shape}")
    print(f"Average of surface area: {average_surface_area(container)}")


# Выводит информацию о всех фигурах в файл
def write(container, ofstream):
    ofstream.write(f"Container stores {len(container)} shapes:\n")
    for shape in container:
        if shape[0] == "sphere":
            sphere.write(shape, ofstream)
        elif shape[0] == "tetrahedron":
            tetrahedron.write(shape, ofstream)
        elif shape[0] == "parallelepiped":
            parallelepiped.write(shape, ofstream)
        else:
            ofstream.write(f"Incorrect figure: {shape}")
    ofstream.write(f"Average of surface area: {average_surface_area(container)}")


# Выводит итоговую информацию о всех оставшихся фигурах в консоль
def write_result(container, ofstream):
    ofstream.write(f"Container after function stores {len(container)} shapes:\n")
    for shape in container:
        if shape[0] == "sphere":
            sphere.write(shape, ofstream)
        elif shape[0] == "tetrahedron":
            tetrahedron.write(shape, ofstream)
        elif shape[0] == "parallelepiped":
            parallelepiped.write(shape, ofstream)
        else:
            ofstream.write(f"Incorrect figure: {shape}")


# Выводит информацию о всех фигурах в тестовый файл
def write_short(container, ofstream):
    for i in range(len(container)):
        if container[i][0] == "sphere":
            sphere.write_short(container[i], ofstream)
        elif container[i][0] == "tetrahedron":
            tetrahedron.write_short(container[i], ofstream)
        elif container[i][0] == "parallelepiped":
            parallelepiped.write_short(container[i], ofstream)
        if i != len(container) - 1:
            ofstream.write("\n")


# Вычисляет среднюю площадь поверхности фигур
def average_surface_area(container):
    area = 0.0
    for shape in container:
        if shape[0] == "sphere":
            area += sphere.surface_area(shape)
        elif shape[0] == "tetrahedron":
            area += tetrahedron.surface_area(shape)
        elif shape[0] == "parallelepiped":
            area += parallelepiped.surface_area(shape)
    return area / len(container)


# удаляет все элементы, у которых площадь поверхности
# больше чем средняя площадь поверхности всех фигур
def filter_figures(container):
    deleted = []
    average_area = average_surface_area(container)
    for shape in container:
        area = 0.0
        if shape[0] == "sphere":
            area += sphere.surface_area(shape)
        elif shape[0] == "tetrahedron":
            area += tetrahedron.surface_area(shape)
        elif shape[0] == "parallelepiped":
            area += parallelepiped.surface_area(shape)
        if area > average_area:
            deleted.append(shape)
    for shape in deleted:
        container.remove(shape)

# ----------------------------- main.py ------------------------------
#  Исполняемый файл программы.
# -----------------------------------------------------------------------
import sys
import container
import time


# Генерирует тест в файл с size фигурами
def generate_test(out_file_name, size):
    cont = []
    container.rnd(cont, size)
    out_file = open(out_file_name, "w")
    container.write_short(cont, out_file)
    out_file.close()


# Выполнение программы, используя данные из файла
def run_from_file(input_file_name, first_out_file_name, second_out_file_name):
    # Начало отсчета времени
    start = time.time()
    cont = []
    input_file = open(input_file_name)
    line = input_file.read()
    input_file.close()
    str_array = line.replace("\n", " ").split(" ")
    print('==> Start')
    fig_num = container.read(cont, str_array)
    if fig_num == -1:
        output_file1 = open(first_out_file_name, 'w')
        output_file1.write("Something wrong with you file, fix it.")
        output_file1.close()
        output_file2 = open(second_out_file_name, 'w')
        output_file2.write("Something wrong with you file, fix it.")
        output_file2.close()
        print("Something wrong with you file, fix it.\n==>Finish")
        exit()
    # Вывод фигур, если их меньше 1000 в консоль
    if len(cont) < 1000:
        print("Container as list of lists {}\n".format(cont))
        container.print_info(cont)
    # Вывод всех фигур
    output_file1 = open(first_out_file_name, 'w')
    container.write(cont, output_file1)
    output_file1.close()
    # Вывод фигур, оставшихся после фильтрации
    output_file2 = open(second_out_file_name, "w")
    container.filter_figures(cont)
    container.write_result(cont, output_file2)
    output_file2.write(f"Time: {time.time() - start} seconds.")
    output_file2.close()

    print('==> Finish')
    print(f"Time: {time.time() - start} seconds.")


# Выполнение программы, используя сгенерированные раномно данные
def run_random(size, first_out_file_name, second_out_file_name):
    # Начало отсчета времени
    start = time.time()
    cont = []
    print('==> Start')
    container.rnd(cont, size)
    # Вывод фигур, если их меньше 1000 в консоль
    if len(cont) < 1000:
        print("Container as list of lists {}\n".format(cont))
        container.print_info(cont)
    # Вывод всех фигур, сгенерированных программой
    output_file1 = open(first_out_file_name, 'w')
    container.write(cont, output_file1)
    output_file1.close()
    # Вывод фигур, оставшихся после фильтрации
    output_file2 = open(second_out_file_name, "w")
    container.filter_figures(cont)
    container.write_result(cont, output_file2)
    output_file2.write(f"Time: {time.time() - start} seconds.")
    output_file2.close()

    print('==> Finish')
    print(f"Time: {time.time() - start} seconds.")


# Выводит информацию о некооректном вводе,
# а так же приводит примеры корректного ввода кмоанды
def error():
    print("Incorrect command line! You must write:"
          "\npython main.py -f <inputFileName> <outputFileName1> <outputFileName1>"
          "\npython main.py -n <positiveNumber> <outputFileName1> <outputFileName1>"
          "\npython main.py --test <positiveNumber> <outputFileName>")
    exit()


if __name__ == '__main__':
    if len(sys.argv) == 4:
        # Для генерации тестов
        if sys.argv[1] != "--test" or (not sys.argv[2].isdigit()):
            error()
        num = int(sys.argv[2])
        if num <= 0:
            error()
        generate_test(sys.argv[3], num)

    # Для выолнения основной задачи программы
    elif len(sys.argv) == 5:
        if sys.argv[1] == "-f":
            run_from_file(sys.argv[2], sys.argv[3], sys.argv[4])
        elif sys.argv[1] == "-n" and sys.argv[2].isdigit():
            num = int(sys.argv[2])
            if num <= 0:
                error()
            run_random(int(sys.argv[2]), sys.argv[3], sys.argv[4])
        else:
            error()
    else:
        error()

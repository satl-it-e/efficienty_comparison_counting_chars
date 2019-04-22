import os
import sys


example_file = 'war_and_peace.txt'
result_file = 'result_{}.txt'
test_one_way = 'test_one_way'
test_file = '_test'


def clear_result_file(filename):
    with open(filename, 'w') as file:
        pass


def run_program(program_name, method_id):
    os.system('./{} {} {} {} >> {}'.format(program_name, method_id, example_file, result_file.format(method_id),
                                           result_file.format(str(method_id) + test_file)))


def parse_file_for_avg_length(filename):
    with open(filename, 'r') as file:
        data = file.readline().strip('\n').split()[-1]
    try:
        return int(data)
    except (TypeError, ValueError):
        raise TypeError('Invalid format of data in file {}.'.format(filename))


def parse_file_for_time(filename):
    with open(filename, 'r') as file:
        data = file.readlines()

    min_time = float('inf')
    try:
        for row in data[:-1]:
            current_time = int(row.strip('\n').split()[-1])
            if current_time < min_time:
                min_time = current_time
    except (TypeError, ValueError):
        raise TypeError('Invalid format of data in file {}.'.format(filename))

    return min_time


def plot_bar(results, avg_length):
    import matplotlib.pyplot as plt
    import numpy as np

    label = list(results.keys())
    index = np.arange(len(label))
    # import pdb; pdb.set_trace()
    plt.bar(index, list(results.values()))
    plt.xlabel('Method ID', fontsize=10)
    plt.ylabel('Time of processing (microseconds)', fontsize=10)
    plt.xticks(index, label, fontsize=10)
    plt.title('Average length: {}'.format(avg_length))
    plt.savefig('result_bar.png')


def main(number_of_tests):
    number_of_methods = 3
    for i in range(1, number_of_methods + 1):
        clear_result_file(result_file.format(i))

    for i in range(1, number_of_methods + 1):
        for j in range(number_of_tests):
            run_program(test_one_way, i)

    average_times = []
    min_times = []
    for i in range(1, number_of_methods + 1):
        cur_avg_length = parse_file_for_avg_length(result_file.format(i))
        cur_min_time = parse_file_for_time(result_file.format(str(i) + test_file))
        average_times.append(cur_avg_length)
        min_times.append(cur_min_time)

    if len(average_times) != average_times.count(average_times[0]):
        raise TypeError('Difference of results.')

    print('Method ID | {}\n{}\n**Time of processing (microseconds):** |{}'.
          format(' | '.join([str(i) for i in range(1, number_of_methods + 1)]), ' | '.join(['---']*(number_of_methods + 1)),
                 ' | '.join(list(map(str, min_times)))))

    results = {i + 1: time for i, time in enumerate(min_times)}
    # plot_bar(results, average_times[0])


if __name__ == "__main__":
    number_of_tests = 10
    if len(sys.argv) > 1:
        try:
            number_of_tests = int(argv[1])
        except (TypeError, ValueError):
            raise ValueError('Invalid argument. Should be integer -- number of tests.')

    main(number_of_tests)

import sys
from time import perf_counter_ns


def three_way_partition(a: list):
    lo = 0
    hi = len(a) - 1
    mid = 0

    while mid <= hi:
        if a[mid] < 0:
            a[lo], a[mid] = a[mid], a[lo]
            lo += 1
            mid += 1
        elif not a[mid]:
            mid += 1
        else:
            a[mid], a[hi] = a[hi], a[mid]
            hi -= 1


def default_sort(a: list):
    a.sort()


if __name__ == "__main__":
    if len(sys.argv) == 4:
        mode = int(sys.argv[1])
        initial_state = int(sys.argv[2])
        qtd_zeros = int(sys.argv[3])
    else:
        print('Insira todos os parametros')
        exit(1)

    v = list(map(lambda v: float(v), input().split(' ')[:-1]))
    v1 = v.copy()

    inicio = perf_counter_ns()
    three_way_partition(v)
    three_way_time = (perf_counter_ns() - inicio) / 1000
    
    inicio = perf_counter_ns()
    default_sort(v1)
    default_sort_time = (perf_counter_ns() - inicio) / 1000
    
    print(f'3-way time\n{three_way_time}us\n\n')
    print(f'Default sort time\n{default_sort_time}us\n\n')

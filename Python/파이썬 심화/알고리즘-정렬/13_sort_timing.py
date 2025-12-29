import time
import random

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def measure_time(sort_func, arr):
    start = time.time()
    sort_func(arr.copy())
    end = time.time()
    return end - start

arr = [random.randint(1, 1000) for _ in range(1000)]

time_selection = measure_time(selection_sort, arr)
time_bubble = measure_time(bubble_sort, arr)
time_insertion = measure_time(insertion_sort, arr)

print(f"선택 정렬 시간: {time_selection:.4f}초")
print(f"버블 정렬 시간: {time_bubble:.4f}초")
print(f"삽입 정렬 시간: {time_insertion:.4f}초")


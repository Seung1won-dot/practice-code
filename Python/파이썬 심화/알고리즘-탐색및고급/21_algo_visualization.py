import time

def visualize_sort(arr, sort_func):
    print(f"정렬 전: {arr}")
    
    steps = []
    def track_step(arr_copy):
        steps.append(arr_copy.copy())
    
    sorted_arr = sort_func(arr.copy(), track_step)
    
    print(f"정렬 후: {sorted_arr}")
    print("\n정렬 과정:")
    for i, step in enumerate(steps[:5]):
        print(f"단계 {i+1}: {step}")
    if len(steps) > 5:
        print(f"... (총 {len(steps)} 단계)")

def bubble_sort_with_tracking(arr, track_step):
    n = len(arr)
    for i in range(n):
        track_step(arr)
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

arr = [64, 34, 25, 12, 22]
visualize_sort(arr, bubble_sort_with_tracking)

def visualize_search(arr, target, search_func):
    print(f"배열: {arr}")
    print(f"찾는 값: {target}")
    
    result = search_func(arr, target)
    if result != -1:
        print(f"인덱스 {result}에서 찾았습니다.")
    else:
        print("찾지 못했습니다.")

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        print(f"검색 범위: [{left}, {right}], 중간값: {arr[mid]}")
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

sorted_arr = [12, 22, 25, 34, 64]
visualize_search(sorted_arr, 25, binary_search)


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    return merge(left_half, right_half)

def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0

    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] < right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1

    while left_idx < len(left):
        result.append(left[left_idx])
        left_idx += 1

    while right_idx < len(right):
        result.append(right[right_idx])
        right_idx += 1

    return result

# Example 
if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5]
    sorted_arr = merge_sort(arr)
    print("Sorted array:", sorted_arr)

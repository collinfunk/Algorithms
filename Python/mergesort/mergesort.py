

def merge(left, right):
    if not left:
        return right

    if not right:
        return left

    if left[0] < right[0]:
        return [left[0]] + merge(left[1:], right)

    return [right[0]] + merge(left, right[1:])

def merge_sort(unsorted):
    if len(unsorted) <= 1:
        return unsorted

    middle = len(unsorted) // 2

    left = unsorted[:middle]
    right = unsorted[middle:]

    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))


def main():
    import random
    unsorted = [random.randint(0, 100) for _ in range(100)]
    print(merge_sort(unsorted))


if __name__ == '__main__':
    main()
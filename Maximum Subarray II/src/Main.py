import sys

def solution(inputs):
    res = sys.maxsize
    left_mins = front(inputs)
    right_mins = back(inputs)
    for i in range(len(inputs) - 1):
        res = min(left_mins[i]+right_mins[i+1], res)
    return res
    
def front(inputs):
    left_mins = [0 for _ in range(len(inputs))]
    min_val = sys.maxsize
    sums = 0
    for i in range(len(inputs)):
        sums = min(inputs[i], sums + inputs[i])
        min_val = min(min_val, sums)
        left_mins[i] = min_val
    return left_mins
def back(inputs):
    right_mins = [0 for _ in range(len(inputs))]
    min_val = sys.maxsize
    sums = 0
    for i in range(len(inputs)-1, 0, -1):
        sums = min(inputs[i], sums + inputs[i])
        min_val = min(min_val, sums)
        right_mins[i] = min_val
    return right_mins

if __name__ == "__main__":
    input_str = "2,-2,-7,6,-8,3,-10,-5"
    inputs = input_str.strip().split(',')
    inputs = list(map(lambda x: int(x),inputs))
    res = solution(inputs)
    print(res)

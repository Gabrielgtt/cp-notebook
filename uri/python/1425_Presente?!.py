# coding: utf=8
def jump(begin, end, goal, i=1):
    if begin == goal:
        return True
    left, right = False, False
    if begin - i > 0:
        left = jump(begin-i, end, goal, i+2)
    if begin + i <= end:
        right = jump(begin+i, end, goal, i+2)
    return left or right

while True:
    n, m = [int(x) for x in raw_input().split()]
    if n == 0 == m:
        break
    if n > 50 or jump(0, n, m):
        print "Let me try!"
    else:
        print "Don't make fun of me!"
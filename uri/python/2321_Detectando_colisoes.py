x0, y0, x1, y1 = map(int, raw_input().split())
a0, b0, a1, b1 = map(int, raw_input().split())

if x0 <= a0 <= x1 or x0 <= a1 <= x1 or a0 <= x0 <= a1 or a0 <= x1 <= a1:
	
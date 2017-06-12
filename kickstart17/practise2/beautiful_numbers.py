import math

# returns f^0 + f^1 + f^2 + ... + f^pl
def rekt(f, pl):
	m = 0
	for i in range(pl+1):
		m += f ** i
	return m

T = int(input())
for t in range(T):
	N = int(input())
	ans = N-1
	pl = 2
	while True:
		f = N ** (1. / float(pl))
		f = math.ceil(f)
		while f >= 2 and rekt(f, pl) > N:
			f -= 1
		if f < 2:
			break
		if rekt(f, pl) == N:
			ans = f
		pl += 1
	print("Case #%d: %d" % (t+1, ans))

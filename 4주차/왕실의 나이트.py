pos = input()

# 열 위치 문자를 숫자로
x = int(ord(pos[0]) - int(ord('a'))) + 1
# 행 위치
y = int(pos[1])

dir = [(2, -1), (2, 1), (-2, -1), (-2, 1), (1, 2), (-1, 2), (1, -2), (-1, -2)]

res = 0
for i in range(len(dir)):
  nx = x + dir[i][0]
  ny = y + dir[i][1]

  if 1 <= nx <= 8 and 1 <= ny <= 8:
    res += 1

print(res)
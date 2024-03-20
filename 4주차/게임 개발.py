n, m = map(int, input().split())
# 현재 위치, 방향
x, y, dir = map(int, input().split())

array = []
for _ in range(m):
  array.append(list(map(int, input().split())))

# 방문했는지 확인 배열
visit = [[0] * m for _ in range(n)]

# 북, 동, 남, 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 왼쪽으로 도는 함수
def turn_left():
  global dir
  dir -= 1
  if dir == -1:
    dir = 3


# 시뮬레이션 시작
res = 1
cnt = 0
while True:
  # 현재 방향을 기준으로 왼쪽 방향부터 갈 곳 정함
  turn_left()
  nx = x + dx[dir]
  ny = y + dy[dir]

  # 아직 가보지 않고 육지
  if visit[nx][ny] == 0 and array[nx][ny] == 0:
    turn_left()
    visit[nx][ny] = 1
    x = nx
    y = ny
    res += 1
    cnt = 0
  # 회전한 이후에 가보지 않은 칸이 없거나 바다
  else:
    cnt += 1
  # 네 방향 모두 이미 가본 칸이거나 바다
  if cnt == 4:
    # 방향 유지한 채로 한 칸 뒤로 가기
    nx = x - dx[dir]
    ny = y - dy[dir]

    # 뒤쪽 방향이 바다인 칸이라 뒤로 갈 수 없는 경우
    if array[nx][ny] == 1:
      break
    # 육지라 뒤로 갈 수 있는 경우
    else:
      x = nx
      y = ny
    cnt = 0

print(res)

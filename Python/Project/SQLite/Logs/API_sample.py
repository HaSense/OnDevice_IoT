import psutil
import pprint

# CPU 정보
print("CPU 정보:")
print(f"CPU 물리 코어 수: {psutil.cpu_count(logical=False)}")
print(f"CPU 논리 코어 수: {psutil.cpu_count(logical=True)}")
print(f"CPU 사용률 (%): {psutil.cpu_percent(interval=1)}")
print()

# 메모리 정보
memory = psutil.virtual_memory()
print("메모리 정보:")
print(f"전체 메모리: {memory.total / (1024 ** 3):.2f} GB")
print(f"사용 가능 메모리: {memory.available / (1024 ** 3):.2f} GB")
print(f"메모리 사용률 (%): {memory.percent}")
print()

# 디스크 정보
print("디스크 정보:")
disk_usage = psutil.disk_usage('/')
print(f"디스크 총 공간: {disk_usage.total / (1024 ** 3):.2f} GB")
print(f"디스크 사용 가능: {disk_usage.free / (1024 ** 3):.2f} GB")
print(f"디스크 사용률 (%): {disk_usage.percent}")
print()

# 네트워크 정보
print("네트워크 정보:")
net_io = psutil.net_io_counters()
print(f"받은 바이트: {net_io.bytes_recv / (1024 ** 2):.2f} MB")
print(f"보낸 바이트: {net_io.bytes_sent / (1024 ** 2):.2f} MB")
print()

# 실행 중인 프로세스 목록
print("실행 중인 프로세스 목록:")
for proc in psutil.process_iter(['pid', 'name']):
    print(proc.info)

# 예쁘게 출력하기 위해 pprint 사용
# pprint.pprint(proc.info)

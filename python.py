brilho = 0
from time import sleep
while True:
    brilho = (brilho + 1) % 256;
    print(brilho)
    sleep(1)
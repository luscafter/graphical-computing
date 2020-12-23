import matplotlib.pyplot as p
import numpy as n

# https://github.com/luscafter/graphical-computing/bitmap-mario/

# Teste o software na ferramenta Colab:
# https://colab.research.google.com/

R = n.array([
    [1, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 0, 1, 1, 1, 1, 1, 0, 1],
    [0, 1, 1, 1, 1, 1, 1, 1, 0],
    [0, 1, 1, 1, 1, 1, 1, 1, 0],
    [1, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 0, 0, 0, 1, 1, 1]
], dtype=n.float32)

G = n.array([
    [1, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 0, 1, 0, 0, 1, 1, 0, 1],
    [0, 0, 1, 0, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 0, 0, 0, 1, 1, 1]
], dtype=n.float32)

B = n.array([
    [1, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 0, 1, 0, 0, 1, 1, 0, 1],
    [0, 0, 1, 0, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 0, 1, 1, 1, 0, 1, 1],
    [1, 1, 1, 0, 0, 0, 1, 1, 1]
], dtype=n.float32)

# Cria-se uma matriz 8x9x3
v = n.zeros((8, 9, 3), dtype=n.float32)

# O vetor recebe a camada RED
v[:,:,0] = R
# O vetor recebe a camada GREEN
v[:,:,1] = G
# O vetor recebe a camada BLUE
v[:,:,2] = B

p.figure(figsize=(3, 3))
image = p.imshow(v)
p.axis("off")
p.show()
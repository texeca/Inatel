import numpy as np
import cv2
import urllib.request


# Abrir a imagem do link ou img = cv2.imread(diretorio_da_imagem//nome_do_arquivo)
resp = urllib.request.urlopen("https://www.oficinadanet.com.br/media/post/27837/750/ruido2.jpg")
img = np.asarray(bytearray(resp.read()), dtype="uint8")
img = cv2.imdecode(img, cv2.IMREAD_COLOR)

kernel = np.ones((3,3),np.uint8)

# Utilização do morphologyEx e blur
closing = cv2.morphologyEx(img,cv2.MORPH_CLOSE,kernel, iterations = 2)
blur = cv2.blur(closing,(15,15))

# Binarização
gray = cv2.cvtColor(blur,cv2.COLOR_BGR2GRAY)
_, mask = cv2.threshold(gray,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
cv2.imshow('Binarização',mask)
cv2.waitKey(0)

#Preenche os quatro cantos da imagem binária
w, h = mask.shape[::-1]
cv2.floodFill(mask, None, (0, 0), 0)
cv2.floodFill(mask, None, (w-1, 0), 0)
cv2.floodFill(mask, None, (0, h-1), 0)
cv2.floodFill(mask, None, (w-1, h-1), 0)
cv2.imshow('mask',mask)
cv2.waitKey(0)

#Lógica AND para obter da imagem original a encontrada pela criação do mask
img = cv2.bitwise_and(img, img, mask=mask )
cv2.imshow('AND',img)
cv2.waitKey(0)

#Canny Edges
edges = cv2.Canny(img, 100,200)
dilate = cv2.dilate(edges,kernel,iterations=1)
dilate = cv2.bitwise_not(dilate)
cv2.imshow('Canny',dilate)
cv2.waitKey(0)

#Lógica OR para retirar da imagem original os pêlos encontrados
img = cv2.bitwise_or(img, img, mask=dilate )
cv2.imshow('Edges',img)
cv2.waitKey(0)

#Interpolação da imagem para preencher os vazios
dilate = cv2.bitwise_not(dilate)
inpaint = cv2.inpaint(img, dilate, 3,cv2.INPAINT_TELEA)
cv2.imshow('InPaint', inpaint)
cv2.waitKey(0)

cv2.destroyAllWindows()
def TSE(num):
    return [num%256,(num//(256))%256,(num//(256*256))%256,(num//(256*256*256))%256]

def FSE(na):
	num=na[0]+na[1]*256+na[2]*256*256+na[3]*256*256*256
	return num

def Createfile(sx,sy):
    start=[0x42,0x4D]
    intm=[0,0,0,0]+TSE(54)+TSE(40)+TSE(sx)+TSE(sy)+[1,0]+[0x18,0]+[0,0,0,0]
    sxp=(sx*3)//4*4
    if sxp<sx*3:
        sxp=sxp+4
    sxp=sxp*sy
    return start+TSE(54+sxp)+intm+TSE(sxp)+[0,0,0,0]+[0,0,0,0]+[0,0,0,0]+[0,0,0,0]


def CreateBMP(name,canv):
	arr=canv[2]
	sizex=canv[0]
	sizey=canv[1]
	f=open(name+".bmp","wb")
	padding=[0]*((-(sizex*3)%4)%4)
	array=Createfile(sizex,sizey)
	for i in range(sizey):
		array+=arr[i]+padding
	ba=bytearray(array)
	f.write(ba)
	f.close()
    

def CreateCanvas(sx,sy,r,g,b):
	createarr=[]
	for i in range(sy):
		createarr.append([b,g,r]*sx)
	return [sx,sy,createarr]

def OpenBMP(filen):
	f=open(filen+".bmp","rb")
	files=list(f.read())
	print(files[0:2])
	if files[0:2]==[0x42,0x4D]:
		print("BMP")
		EX=FSE(files[10:14])
		sx=FSE(files[18:22])
		sy=FSE(files[22:26])
		print(sx,sy,EX)
	canv=CreateCanvas(sx,sy,0,0,0)
	toprint=[]
	nsx=(sx*3//4)*4
	if nsx<sx*3:
		nsx=nsx+4
	print(nsx)
	for y in range(sy):
		pos=EX+y*nsx
		toprint.append(files[pos:(pos+sx*3)])
	print("Done")
	canv[2]=toprint
	f.close()
	return canv


canv = OpenBMP("L3")

seen=[]
for i in range(30):
    seen.append([0]*30)

result=""
data=""
am=0
for x in range(30):
    for y in range(30):
        b=canv[2][y][x*3]
        g=canv[2][y][x*3+1]
        r=canv[2][y][x*3+2]
        ty=29-y
        if b==0 and g==0 and r==0:
            result+="E"+str(x//16)+hex(x%16)[2]+str(ty//16)+hex(ty%16)[2]+";"
            am=am+1
        if b==255 and g==0 and r==0:
            data+="P"+str(x//16)+hex(x%16)[2]+str(ty//16)+hex(ty%16)[2]+";"
        if r==255 and g==0 and b==0:
            data+="T"+str(x//16)+hex(x%16)[2]+str(ty//16)+hex(ty%16)[2]+";"
        if g>0 and b==0 and r==0 and seen[x][y]==0:
            dx=1
            while canv[2][y][x*3+dx*3+1]==g:
                dx=dx+1

            for kx in range(dx):
                for ky in range(dx):
                    seen[x+kx][y+ky]=1
            am=am+1
            result+="B"+str(x//16)+hex(x%16)[2]+str(ty//16)+hex(ty%16)[2]+str((dx-1)//16)+hex((dx-1)%16)[2]+";"

print(result+":",am, data)
            


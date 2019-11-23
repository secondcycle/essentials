


if __name__ == '__main__':
    x = int(raw_input())
    y = int(raw_input())
    z = int(raw_input())
    n = int(raw_input())

    outList = []

    for xCord in range(0,x+1):
        for yCord in range(0,y+1):
            for zCord in range(0, z+1):
                if(xCord + yCord + zCord != n):
                    outList.append([xCord, yCord, zCord])

    print(outList)
                
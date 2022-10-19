a, b, c, d = eval(input("Please input your equation coefficient:\n"))
b /= (-a)
c /= (-a)
d /= (-a)


class FibIter(object):
    def __init__(self):
        self.listArray = [0, 1, 1]

    def Fibo(self, n):
        if n <= 2:
            return self.listArray[n]
        else:
            for i in range(3, n+1):
                self.listArray.append(
                    b*self.listArray[i-1]+c*self.listArray[i-2]+d*self.listArray[i-3])
        return self.listArray[n]


A = FibIter()
A.Fibo(45)
for j in range(2, 45):
    print(A.listArray[j]/A.listArray[j-1])

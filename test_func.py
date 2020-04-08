def Maxsub_sum(n,list1):
    temp = 0
    max_sum = 0
    for i in list1:
        i = int(i)
        temp = max(temp+i,i)
        temp = max(temp,0)
        max_sum = max(temp,max_sum)
    print("最大连续子数组的和：",max_sum)
    return max_sum
n = int(input("请输入序列长度n:"))
list1 = []
for i in range(n):
    print("请输入第%d个整数:"%i,end=' ')
    list1.append(input())
Maxsub_sum(n,list1)

# def test1():
#     n = 1
#     list1 = [1]
#     assert 1 == Maxsub_sum(n,list1)
# def test2():
#     n = 1
#     list1 = [-1]
#     assert 0 == Maxsub_sum(n,list1)
# def test3():
#     n = 2
#     list1 = [-1,2]
#     assert 2 == Maxsub_sum(n,list1)
# def test4():
#     n = 3
#     list1 = [-1,2,-1]
#     assert 2 == Maxsub_sum(n,list1)
# def test5():
#     n = 3
#     list1 = [-1,2,3]
#     assert 5 == Maxsub_sum(n,list1)
# def test6():
#     n = 4
#     list1 = [-1,2,-1,3]
#     assert 4 == Maxsub_sum(n,list1)
# def test7():
#     n = 5
#     list1 = [-1,3,-2,2,2]
#     assert 5 == Maxsub_sum(n,list1)



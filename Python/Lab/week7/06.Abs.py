def returnAbs(*args):
    lamFunc=lambda num: abs(num)
    l=[lamFunc(num) for num in args]
    print(l)
returnAbs(5.2,-12.0,-8.4,34)
returnAbs(31.5,-4.8,6,-71.2,-3)
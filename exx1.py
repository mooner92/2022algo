def ars(one, two, *args, three):
    print(one + two + sum(args))
    print(args)


ars(3, 4, 5, 6, 7)

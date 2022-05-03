def decorator(func):
    def inner(*args, **kargs):
        print("prints before the functions executes")
        result = func(*args)
        print("result is = ", result, "-", *args, "-", **kargs)
        func(*args)
        print("prints after the functions executes")
    return inner


@decorator
def add(x, y, **z):
    return (x+y)

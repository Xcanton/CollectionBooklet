class MyHashMap:

    def __init__(self):
        self.__dict = dict()

    def put(self, key: int, value: int) -> None:
        self.__dict[key] = value

    def get(self, key: int) -> int:
        if key in self.__dict.keys():
            return self.__dict[key]
        else:
            return -1

    def remove(self, key: int) -> None:
        if key in self.__dict.keys():
            del self.__dict[key]
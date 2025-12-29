import pickle

data = {
    "name": "홍길동",
    "age": 25,
    "scores": [85, 90, 88]
}

with open("data.pkl", "wb") as f:
    pickle.dump(data, f)

with open("data.pkl", "rb") as f:
    loaded_data = pickle.load(f)
    print(loaded_data)

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def __repr__(self):
        return f"Person(name={self.name}, age={self.age})"

person = Person("김철수", 30)

with open("person.pkl", "wb") as f:
    pickle.dump(person, f)

with open("person.pkl", "rb") as f:
    loaded_person = pickle.load(f)
    print(loaded_person)


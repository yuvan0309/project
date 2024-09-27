class TextInput:
    def __init__(self):
        self.text=""
    def add(self, text):
        self.text+=text
    def get_value(self):
        return self.text

class NumericInput:
    def __init__(self):
        self.Value=""
    def add(self,Value):
        if Value.isdigit():
            self.Value+=Value
    def get_value(self):
        return self.Value

if __name__ == '__main__':
    input = NumericInput()
    input.add("6")
    input.add("b")
    input.add("9")
    print(input.get_value())
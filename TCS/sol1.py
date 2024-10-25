def convert_to_number(word):
    """Converts a word representing a number into an integer."""
    digit_map = {
        "one": 1, "two": 2, "three": 3, "four": 4,
        "five": 5, "six": 6, "seven": 7, "eight": 8, "nine": 9
    }
    number = 0
    for digit in word.split("c"):
        if digit not in digit_map:
            return None
        number = number * 10 + digit_map[digit]
    return number

def evaluate_expression(expression):
    """Evaluates a Prabhu expression and returns the result."""
    operation_map = {
        "add": "+", "sub": "-", "mul": "*", "rem": "%", "pow": "^"
    }
    stack = []
    operator_stack = []

    for word in expression.split():
        if word in operation_map:
            # Handle operator precedence using a stack
            while operator_stack and operation_map[operator_stack[-1]] >= operation_map[word]:
                op2 = stack.pop()
                op1 = stack.pop()
                result = eval(f"{op1}{operation_map[operator_stack.pop()]}{op2}")
                stack.append(result)
            operator_stack.append(word)
        else:
            number = convert_to_number(word)
            if number is None:
                return "expression evaluation stopped invalid words present"
            stack.append(number)

    # Evaluate any remaining operators
    while operator_stack:
        op2 = stack.pop()
        op1 = stack.pop()
        result = eval(f"{op1}{operation_map[operator_stack.pop()]}{op2}")
        stack.append(result)

    return stack[0]

if __name__ == "__main__":
    expression = input()
    result = evaluate_expression(expression)
    print(result)
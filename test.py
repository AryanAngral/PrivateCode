# Sample list of numbers
numbers = [12, 5, 7, 19, 3, 25, 11]

# Step 1: Initialize 'largest' and 'smallest' to the first element of the list
largest = numbers[0]
smallest = numbers[0]
sum_of_numbers = 0

# Step 2: Iterate through each element in the list
for num in numbers:
    # Check if the current element is greater than 'largest'
    if num > largest:
        largest = num
    # Check if the current element is smaller than 'smallest'
    if num < smallest:
        smallest = num
    # Add the current element to the sum
    sum_of_numbers += num

# Step 3: Calculate the average
average = sum_of_numbers / len(numbers)

# Step 4: Output the results
print("Largest element:", largest)
print("Smallest element:", smallest)
print("Average of the list:", average)

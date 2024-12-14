#write a python program to convert celsius to fahrenheit
def cel_far(celsius):
    fahrenheit=(celsius*9/5)+32
    print(f"{celsius} celsius is {fahrenheit:.2f} fahrenheit")
def main():
    print("Temperature Conversion Program")
    print("   Celsius to fahrenheit      ")
    try:
        inp=float(input("Enter the temperature in Celsius "))
        cel_far(inp)
    except:
        print("Enter correct input ")
    
if __name__=="__main__":
    main()


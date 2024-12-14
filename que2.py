#create a csv file and add 5 rows with 3 columns column1(name), column2(salary), column3(month) and create a new #column where salary*12 and update the original file.
import csv
def create_csv(file_name):
    with open(file_name,mode='w',newline='') as file:
        writer=csv.writer(file)
        writer.writerow(["Name", "Salary", "Month"])
        writer.writerow(["Aryan", 300000, "January"])
        writer.writerow(["Arya", 35000, "February"])
        writer.writerow(["Dhruv", 40000, "March"])
        writer.writerow(["Akshit", 45000, "April"])
        writer.writerow(["Suriyansh", 50000, "May"])
def update_csv(file_name):
    rows = []
    with open(file_name, mode='r') as file:
        reader = csv.reader(file)
        header = next(reader)
        header.append("Annual Salary")
        for row in reader:
            if len(row) == 3:
                annual_salary = int(row[1]) * 12
                row.append(annual_salary)
            rows.append(row)
    with open(file_name, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(header)
        writer.writerows(rows)
def main():
    file_name = "employee_data.csv"
    create_csv(file_name)
    update_csv(file_name)
    print(f"CSV file '{file_name}' created and updated successfully.")
if __name__ == "__main__":
    main()

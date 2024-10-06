names = "sharon, amal, abdul, anna".split(",")

count = 0
for name in names:
    count = name.lstrip().count('a')
    print(count, end=" ")
    count += int(count)

print(f"= {count}")
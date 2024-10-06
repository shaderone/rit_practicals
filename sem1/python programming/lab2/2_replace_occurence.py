s = input("Enter a string: ")

print(f'{s[0]}{s[1:-1].replace(s[0],'$')}')
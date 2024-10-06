#st = input("Enter a string: ")
st = "sharoning"

if st[-3:] == "ing" :
    print(st.replace(st[-3:], "ly"))
else: 
    print(st+"ing")

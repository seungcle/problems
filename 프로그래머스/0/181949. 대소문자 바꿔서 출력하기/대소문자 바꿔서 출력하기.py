str = input()
ans = ""
for i in range(len(str)):
    if 'a'<= str[i] <= 'z':
        ans += str[i].upper()
    elif 'A'<=str[i]<='Z':
        ans += str[i].lower()
print(ans)